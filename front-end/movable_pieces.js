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
				send_command("move "+window.fromCell+" "+window.toCell, function(response_data){

					// Force the browser to get the new board state
					// if the response was not an error
					if (response_data.status != 3)
						update_board();

				});
				
				// Reset selected cells
				$('td.selected').removeClass('selected');
				window.fromCell = "";
				window.toCell = "";											
				
				
			}
		},500);


	}
	else
	{	
		$(this).removeClass('selected');
		window.fromCell = "";
	}
});