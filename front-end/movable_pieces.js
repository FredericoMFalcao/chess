// Initialize variables
window.fromCell = "";
window.toCell = "";

// Make chess board cells clickable
jQuery('table#board td').on('click', function() {

	// Check that the user is not clicking a cell that was already selected
	if(!$(this).hasClass('selected'))
	{
		// Save the id of the cell clicked
		if (window.fromCell == "")
			window.fromCell = $(this).attr('id');
		else
			window.toCell = $(this).attr('id');

		// Add the styling class ('dashed border')
		$(this).addClass('selected');

		// Wait half a second (animation)
		// so that the user understands what is happening
		window.setTimeout(function(){

			// destination click: one cell was already selected
			if ($('td.selected').length == 2)
			{
				// Action
				// ----------------

				// Send the move intention to the server
				$.ajax({'url':'/chess.php','data':{'command':'move '+window.fromCell+' '+window.toCell,'json':1}, 
				'success':function(data){
					alert(data.message);
					
					update_board();
					
					// Reset selected cells
					$('td.selected').removeClass('selected');
					window.fromCell = "";
					window.toCell = "";
					
					
				},
				'error':function(jqXHR, error_msg){
					alert("ERROR: "+error_msg);
					
					// Reset selected cells
					$('td.selected').removeClass('selected');
					window.fromCell = "";
					window.toCell = "";
					
				}});
				
				
				
			}
		},500);


	}
	else
	{	
		$(this).removeClass('selected');
		window.fromCell = "";
	}
});