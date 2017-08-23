// Query the server about the pieces location
function update_board()
{
	$.ajax({'url':'/chess.php',
			'data':{'command':'print-json', 'json':1},
			'dataType':'json', 
			'success':function(chess_board)
			{
				for (row_no in chess_board["board"])
				{
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
				
			},
			'error':function(jqXHR, error_str)
			{
				alert("AJAX ERROR: "+ error_str);
			}
	});
}
