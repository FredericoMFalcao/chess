<?php
// 1. Pass the correct header to the browser
if (isset($_GET['json']))
	header("Content-type: application/json");
else
	header("Content-type: text/plain");

// 2. Handle Sessions
session_start();
if(!isset($_SESSION['id']))
	$_SESSION['id'] = md5(rand());

if (file_exists($_SESSION['id']."txt"))
	$prev_commands = explode("\n", file_get_contents($_SESSION['id']."txt"));
else
	$prev_commands = array();

if (isset($_POST['command']))
	$prev_commands

$_GET['load_from_file'] = $_SESSION['id'].".txt";


// 3. Execute the "chess" file
// 3.1 Pass the GET arguments as CLI arguments
passthru(__DIR__."/back-end/chess".
		array_reduce($_GET,
			function($a, $b){return " --$a=$b";}
			)
		);