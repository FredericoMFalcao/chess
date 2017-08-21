<?php
// 1. Execute the "chess" file
// 2. pass the GET arguments as CLI arguments
passthru(__DIR__."/back-end/chess".array_reduce($_GET,function($a, $b){return " $a=$b";}));