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
				html_data = $('#console_output').html();		
				html_data += "\n"+response_data.message;		
				$('#console_output').html(html_data);

				
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
				
				success_fn(response_data);
				
				
	}});
}