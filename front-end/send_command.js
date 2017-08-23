function send_command(input_data, success_fn)
{

	// Capture either direct text
	// or the input element
	if (typeof input_data == "string")
		command = input_data;
	else
		command = $(input_data).find('input:eq(0)').val();


	
	// Send the requested command to the server
	$.ajax({url:'/chess.php',
			data:{'command':command, 'json':1},
			success:function(response_data){

				// Log the response in the terminal window
				if (typeof response_data.message == "string")
				{
					html_data = $('#console_output').html();		
					html_data += "\n"+response_data.message;		
					$('#console_output').html(html_data);					
					
				}

				
				// 1 - OUTPUT_MODE_QUESTION
				if (response_data.status == 1)
				{
					prompt(response_data.message);
				}
				// 2 - OUTPUT_MODE_STATUS
				if (response_data.status == 2)
				{
					$('#status_panel').html("").append(
						$('<div/>').addClass('alert').addClass('alert-success').text(response_data.message)
					);
				}
				
				// 3 - OUTPUT_MODE_ERROR
				if (response_data.status == 3)
				{
					$('#status_panel').html("").append(
						$('<div/>').addClass('alert').addClass('alert-danger').text(response_data.message)
					);						
					
				}

				// 4 - OUTPUT_MODE_BOARD_STATE
				if (response_data.status == 4)
				{
					// Variable alias
					chess_board = response_data;

					// Loop through all the rows in the board
					for (row_no in chess_board["board"])
					{
						// Loop through all the cols in the board
						for(col_no in chess_board["board"][row_no])
						{
							// Find the table cell
							table_cell = $('table#board tr').eq(row_no).find('td').eq(col_no);

							// Remove any content there
							table_cell.html("");
						
							// Check if this house has a piece
							if (chess_board["board"][row_no][col_no] != "")
								// Find the correct cell
								table_cell.append(
										// insert a new chess piece there
									$('<div/>').addClass('chess_piece').addClass(chess_board["board"][row_no][col_no])
								);
						}
					}
				
					// Add the images of the black pieces lost
					for(no in chess_board['lost_black_pieces'])
					{
						$('table#lost_black_pieces tr:eq(0) td').eq(no).html("").append(
							// insert a new chess piece there
							$('<div/>')
								.addClass('chess_piece')
								.addClass('black')
								.addClass(chess_board["lost_black_pieces"][no])						
						);
				
					}

					// Add the images of the white pieces lost
					for(no in chess_board['lost_white_pieces'])
					{
						$('table#lost_white_pieces tr:eq(0) td').eq(no).html("").append(
							// insert a new chess piece there
							$('<div/>')
								.addClass('chess_piece')
								.addClass('white')
								.addClass(chess_board["lost_white_pieces"][no])						
						);
				
					}
				}

				// Call the callback provided if any
				if (typeof success_fn == "function")					
					success_fn(response_data);
				
				
	}});
}