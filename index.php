<?php session_start(); 
//
// SESSION MANAGEMENT
//

// 0. Get previous commands
if (isset($_SESSION['id']))
{
	// User has logged in before
	if (file_exists(__DIR__."/".md5($_SESSION['id']).".txt"))
	{
		// User has issued commands before		
		$previous_commands = explode("\n", file_get_contents(__DIR__."/".md5($_SESSION['id']).".txt"));
	}
	else
	{
		$previous_commands = array();
	}
	
}
else
{
	// Fisrt time login
	$_SESSION['id'] = md5(rand());
	$previous_commands = array();
}

// 1. Save current command
if (isset($_GET['command']))
{
	$previous_commands[] = $_GET['command'];
	file_put_contents(__DIR__."/".md5($_SESSION['id']).".txt", implode("\n",$previous_commands));	
}

?>
<html>
<head><title>Chess Game</title>
</head>
<body>
<pre>
<?php

$descriptorspec = array(
   0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
   1 => array("pipe", "w")  // stdout is a pipe that the child will write to
);

$cwd = '/tmp';


$process = proc_open(__DIR__."/chess", $descriptorspec, $pipes, $cwd);

if (is_resource($process)) {
    // $pipes now looks like this:
    // 0 => writeable handle connected to child stdin
    // 1 => readable handle connected to child stdout
    // Any error output will be appended to /tmp/error-output.txt

	// send each previous command
	foreach($previous_commands as $command)
		fwrite($pipes[0], $command."\n");

    fclose($pipes[0]);

	$output_buffer = "";

	// Set STDIN to non-blocking
	stream_set_blocking($pipes[1], 0);
	
	$char = stream_get_contents($pipes[1],1);
	$output_buffer .= $char;
	$i = 0;
	
	while ($char != ">" && $char != "?" && $i < 1024)
	{	
		$char = stream_get_contents($pipes[1],1);
		$output_buffer .= $char;
		echo $i."\n";
		$i++;
	}
	
	echo $output_buffer;	
    fclose($pipes[1]);

    // It is important that you close any pipes before calling
    // proc_close in order to avoid a deadlock
    $return_value = proc_close($process);
	echo "\nExecutable finished with code: $return_value";

}
else
	echo "ERROR: Could not run \"chess\" executable.";

?>
</pre>
<form method="GET" action="/">
Command: <input type="text" name="command"/>
</form>

</body>
</html>
