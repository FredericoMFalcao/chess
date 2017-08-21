function send_command(form_obj)
{

	var command = $(form_obj).find('input:eq(0)').val();
	
	// Send the requested command to the server
	$.ajax({'url':'/chess.php',data:{'command':command},'success':function(response_data){
		html_data = $('#console_output').html();
		
		html_data += response_data;
		
		$('#console_output').html(html_data);
	}});
}