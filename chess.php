<?php
// 1. Pass the correct header to the browser
if (isset($_GET['json']))
	header("Content-type: application/json");
else
	header("Content-type: text/plain");

// 2. Execute the "chess" file
// 2.1 Pass the GET arguments as CLI arguments
passthru(__DIR__."/back-end/chess".
		array_reduce($_GET,
			function($a, $b){return " --$a=$b";}
			)
		);