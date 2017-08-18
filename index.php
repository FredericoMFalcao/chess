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
			<td><div class="chess_piece black tower"></div></td>
			<td><div class="chess_piece black horse"></div></td>
			<td><div class="chess_piece black bishop"></div></td>
			<td><div class="chess_piece black queen"></div></td>
			<td><div class="chess_piece black king"></div></td>
			<td><div class="chess_piece black bishop"></div></td>
			<td><div class="chess_piece black horse"></div></td>
			<td><div class="chess_piece black tower"></div></td>
		</tr>
		<tr>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
			<td><div class="chess_piece black pawn"></div></td>
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
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
			<td><div class="chess_piece white pawn"></div></td>
		</tr>
		<tr>
			<td><div class="chess_piece white tower"></div></td>
			<td><div class="chess_piece white horse"></div></td>
			<td><div class="chess_piece white bishop"></div></td>
			<td><div class="chess_piece white queen"></div></td>
			<td><div class="chess_piece white king"></div></td>
			<td><div class="chess_piece white bishop"></div></td>
			<td><div class="chess_piece white horse"></div></td>
			<td><div class="chess_piece white tower"></div></td>
		</tr>
	</tbody>
</table>		

<form method="GET" action="/">
Command: <input type="text" name="command"/>
</form>

</body>
</html>
