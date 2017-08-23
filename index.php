<html>
<head>
	<title>Chess Game</title>
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

	<!-- Latest compiled and minified JavaScript -->
	<script src="/front-end/jQuery.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" ></script>

	<style>
		table#board,table#board td {
		    border: 1px solid #bfbfbf;
		}

		table#board td:nth-child(even) {background-color:#D8D8D8;}
		table#board tr:nth-child(even) td {background-color:#E5E5E5;}
		td {height:60px;width:60px;}
		
		.chess_piece {height:60px; width:60px; background-image:url('/front-end/chess_pieces.png'); background-repeat:no-repeat;}
		
		.black {background-position-x: 0px;}
		.white {background-position-x: -60px;}

		.tower {background-position-y: 0px;}
		.horse {background-position-y: -60px;}
		.bishop {background-position-y: -120px;}
		.queen {background-position-y: -180px;}
		.king {background-position-y: -240px;}
		.pawn {background-position-y: -300px;}
		
		table#board td.selected{border:2px dashed #7F7F7F;}
		
		</style>
</head>

<body class="container">
<div>
		 <!-- Nav tabs -->
	  <ul class="nav nav-tabs" role="tablist">
	    <li role="presentation" class="active"><a href="javascript:void(0);" data-target="#gui" role="tab" data-toggle="tab">Board</a></li>
	    <li role="presentation"><a href="javascript:void(0);" data-target="#cli"  role="tab" data-toggle="tab">Console</a></li>
	  </ul>
	 <div class="tab-content">
		<div id="status_panel">
			<div class="alert alert-info">Welcome to the Chess Game!</div>
		</div>
		 
		<div role="tabpanel" class="tab-pane active" id="gui">
			<div class="row">
				<div class="col-xs-12 col-sm-6">
					<table boder="1" id="board">
				<tbody>
					<tr>
						<td id="a8"></td>
						<td id="b8"></td>
						<td id="c8"></td>
						<td id="d8"></td>
						<td id="e8"></td>
						<td id="f8"></td>
						<td id="g8"></td>
						<td id="h8"></td>
					</tr>
					<tr>
						<td id="a7"></td>
						<td id="b7"></td>
						<td id="c7"></td>
						<td id="d7"></td>
						<td id="e7"></td>
						<td id="f7"></td>
						<td id="g7"></td>
						<td id="h7"></td>
					</tr>
					<tr>
						<td id="a6"></td>
						<td id="b6"></td>
						<td id="c6"></td>
						<td id="d6"></td>
						<td id="e6"></td>
						<td id="f6"></td>
						<td id="g6"></td>
						<td id="h6"></td>
					</tr>
					<tr>
						<td id="a5"></td>
						<td id="b5"></td>
						<td id="c5"></td>
						<td id="d5"></td>
						<td id="e5"></td>
						<td id="f5"></td>
						<td id="g5"></td>
						<td id="h5"></td>
					</tr>
					<tr>
						<td id="a4"></td>
						<td id="b4"></td>
						<td id="c4"></td>
						<td id="d4"></td>
						<td id="e4"></td>
						<td id="f4"></td>
						<td id="g4"></td>
						<td id="h4"></td>
					</tr>
					<tr>
						<td id="a3"></td>
						<td id="b3"></td>
						<td id="c3"></td>
						<td id="d3"></td>
						<td id="e3"></td>
						<td id="f3"></td>
						<td id="g3"></td>
						<td id="h3"></td>
					</tr>
					<tr>
						<td id="a2"></td>
						<td id="b2"></td>
						<td id="c2"></td>
						<td id="d2"></td>
						<td id="e2"></td>
						<td id="f2"></td>
						<td id="g2"></td>
						<td id="h2"></td>
					</tr>
					<tr>
						<td id="a1"></td>
						<td id="b1"></td>
						<td id="c1"></td>
						<td id="d1"></td>
						<td id="e1"></td>
						<td id="f1"></td>
						<td id="g1"></td>
						<td id="h1"></td>
					</tr>
				</tbody>
			</table>
				</div>
				<div class="col-xs-12 col-sm-6">
					<strong>White pieces taken:</strong>					
					<table id="lost_white_pieces">
						<tbody>
							<tr><td></td><td></td><td></td><td></td><td></td><td></td></tr>
						</tbody>
					</table>
					<br><br>
					<strong>Black pieces taken:</strong>					
					<table id="lost_black_pieces">
						<tbody>
							<tr><td></td><td></td><td></td><td></td><td></td><td></td></tr>
						</tbody>
					</table>
					
				</div>
			</div>
		</div><!-- /#gui -->

		<div role="tabpanel" class="tab-pane" id="cli"  >

			<form method="GET" action="/" onsubmit="send_command(this);return false;">
				<div class="input-group">
					  <input type="text" class="form-control" name="command" placeholder="type your command here ..." />
				      <span class="input-group-btn">
				        <button class="btn btn-default" type="button">Send</button>
				      </span>				      
				</div><!-- /input-group -->
			</form>
			<pre id="console_output" style="max-height:600px; overflow-y:scroll;">
			</pre>
		</div><!-- /#cli -->
	</div><!-- /.tab-content -->
</div>




<script src="/front-end/send_command.js"></script>
<script src="/front-end/movable_pieces.js"></script>
<script src="/front-end/update_board.js"></script>
<script>/* initiate board */ update_board();</script>







</body>
</html>
