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
			},
			'error':function(jqXHR, error_str)
			{
				alert("AJAX ERROR: "+ error_str);
			}
	});
}
