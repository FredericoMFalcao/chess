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

if (!isset($_GET['save-to-file'])) $_GET['save-to-file'] = $_SESSION['id'].".bin";
if (!isset($_GET['load-from-file']) 
	&& file_exists($_SESSION['id'].".bin")) $_GET['load-from-file'] = $_SESSION['id'].".bin";

// 3. Mark execution as script
$_GET['script'] = 1;

// 4. Pass the command provided if any
if (isset($_POST['command'])) $_GET['command'] = $_POST['command'];

// 5. Pass the GET arguments as CLI arguments
$cli_args = ""; foreach($_GET as $k => $v) $cli_args .= " \"--$k=$v\"";

// 6. Execute the "chess" binary
passthru("back-end/chess ".$cli_args);
