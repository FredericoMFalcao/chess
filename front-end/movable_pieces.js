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

		// Wait half a second
		window.setTimeout(function(){
			// 
			if ($('td.selected').length == 2)
			{
				// Action
				// ----------------
				
				// Move the piece
				$('#'+window.fromCell+' div').appendTo($('#'+window.toCell));
				
				// Eat piece
				if ($('#'+window.toCell+' div').length == 2)
				{
					$('#'+window.toCell+' div:eq(0)').fadeOut(400, function(){
						$(this).remove()
					});
				}
				

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