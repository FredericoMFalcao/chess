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

// 3. Execute the "chess" file
// 3.1 Pass the GET arguments as CLI arguments
passthru(__DIR__."/back-end/chess".
		array_reduce($_GET,
			function($a, $b){return " --$a=$b";}
			)
		);