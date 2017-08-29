<?php require("parsedown.php"); $parsedown = new Parsedown();
$data = file_get_contents("tickets.csv"); $data = explode("\r\n", $data); ?>
<html>
<head>
	<title>Chess Tickets</title>

	<!-- Bootstrap CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" >
	<script src="/front-end/jQuery.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" ></script>
	
</head>
<body class="container">
	<table class="table">
		<thead>
			<tr>
				<?php foreach(explode("\t",$data[0]) as $cell) echo "<th>$cell</th>"; unset($data[0]); ?>
			</tr>
		</thead>
		<tbody>			
			<?php foreach($data as $line)
				  {
					  echo "<tr>";
					  foreach(explode("\t", $line) as $cell) 
					  {
						  // Add Styling
						  $classes = array();
						  if ($cell == "Not Done") $classes[] = "bg-danger";
						  if ($cell == "Done") $classes[] = "bg-success";
						  
						  $cell = str_replace("\n", "<br>", $cell);
						  
						  
						  echo "<td class=\"".implode(" ", $classes)."\">".$parsedown->text($cell)."</td>";
					  }
					  echo "</tr>";
				  }
?>
		</tbody>
	</table>
</body>
</html>