<html>
<head>
	<title>Chess Game</title>
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

	<!-- Latest compiled and minified JavaScript -->
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
	<style>
		table, th, td {
		    border: 1px solid #bfbfbf;
		}

		td:nth-child(even) {background-color:#D8D8D8;}
		td {height:60px;width:60px;}
		
		.chess_piece {height:60px; width:60px; background-image:url('/chess_pieces.png'); background-repeat:no-repeat;}
		
		.black {background-position-x: 0px;}
		.white {background-position-x: -60px;}

		.tower {background-position-y: 0px;}
		.horse {background-position-y: -60px;}
		.bishop {background-position-y: -120px;}
		.queen {background-position-y: -180px;}
		.king {background-position-y: -240px;}
		.pawn {background-position-y: -300px;}
		
		</style>
</head>
<body>
<table boder="1">	
	<tbody>
		<tr>
			<td><div draggable="true"  class="chess_piece black tower"></div></td>
			<td><div draggable="true"  class="chess_piece black horse"></div></td>
			<td><div draggable="true"  class="chess_piece black bishop"></div></td>
			<td><div draggable="true"  class="chess_piece black queen"></div></td>
			<td><div draggable="true"  class="chess_piece black king"></div></td>
			<td><div draggable="true"  class="chess_piece black bishop"></div></td>
			<td><div draggable="true"  class="chess_piece black horse"></div></td>
			<td><div draggable="true"  class="chess_piece black tower"></div></td>
		</tr>
		<tr>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
			<td><div draggable="true"  class="chess_piece black pawn"></div></td>
		</tr>
		<tr>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
			<td><div draggable="true"  class="chess_piece white pawn"></div></td>
		</tr>
		<tr>
			<td><div draggable="true"  class="chess_piece white tower"></div></td>
			<td><div draggable="true"  class="chess_piece white horse"></div></td>
			<td><div draggable="true"  class="chess_piece white bishop"></div></td>
			<td><div draggable="true"  class="chess_piece white queen"></div></td>
			<td><div draggable="true"  class="chess_piece white king"></div></td>
			<td><div draggable="true"  class="chess_piece white bishop"></div></td>
			<td><div draggable="true"  class="chess_piece white horse"></div></td>
			<td><div draggable="true"  class="chess_piece white tower"></div></td>
		</tr>
	</tbody>
</table>		

<form method="GET" action="/">
Command: <input type="text" name="command"/>
</form>

</body>
</html>
