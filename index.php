<html>
<head>
	<title>Chess Game</title>
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

	<!-- Latest compiled and minified JavaScript -->
	<script src="/jQuery.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" ></script>

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
		
		.selected{border:2px dashed #7F7F7F;}
		
		</style>
</head>
<script src="/jQuery.js"></script>
<body class="container">
<div>
		 <!-- Nav tabs -->
	  <ul class="nav nav-tabs" role="tablist">
	    <li role="presentation" class="active"><a href="javascript:void(0);" data-target="#gui" role="tab" data-toggle="tab">GUI</a></li>
	    <li role="presentation"><a href="javascript:void(0);" data-target="#cli"  role="tab" data-toggle="tab">CLI</a></li>
	  </ul>
	 <div class="tab-content">
		<div role="tabpanel" class="tab-pane active" id="gui"  >

			<table boder="1" id="board">
				<tbody>
					<tr>
						<td id="a8" ><div class="chess_piece black tower"></div></td>
						<td id="b8"><div class="chess_piece black horse"></div></td>
						<td id="c8"><div class="chess_piece black bishop"></div></td>
						<td id="d8"><div class="chess_piece black queen"></div></td>
						<td id="e8"><div class="chess_piece black king"></div></td>
						<td id="f8"><div class="chess_piece black bishop"></div></td>
						<td id="g8"><div class="chess_piece black horse"></div></td>
						<td id="h8"><div class="chess_piece black tower"></div></td>
					</tr>
					<tr>
						<td id="a7"><div class="chess_piece black pawn"></div></td>
						<td id="b7"><div class="chess_piece black pawn"></div></td>
						<td id="c7"><div class="chess_piece black pawn"></div></td>
						<td id="d7"><div class="chess_piece black pawn"></div></td>
						<td id="e7"><div class="chess_piece black pawn"></div></td>
						<td id="f7"><div class="chess_piece black pawn"></div></td>
						<td id="g7"><div class="chess_piece black pawn"></div></td>
						<td id="h7"><div class="chess_piece black pawn"></div></td>
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
						<td id="a2"><div class="chess_piece white pawn"></div></td>
						<td id="b2"><div class="chess_piece white pawn"></div></td>
						<td id="c2"><div class="chess_piece white pawn"></div></td>
						<td id="d2"><div class="chess_piece white pawn"></div></td>
						<td id="e2"><div class="chess_piece white pawn"></div></td>
						<td id="f2"><div class="chess_piece white pawn"></div></td>
						<td id="g2"><div class="chess_piece white pawn"></div></td>
						<td id="h2"><div class="chess_piece white pawn"></div></td>
					</tr>
					<tr>
						<td id="a1"><div class="chess_piece white tower"></div></td>
						<td id="b1"><div class="chess_piece white horse"></div></td>
						<td id="c1"><div class="chess_piece white bishop"></div></td>
						<td id="d1"><div class="chess_piece white queen"></div></td>
						<td id="e1"><div class="chess_piece white king"></div></td>
						<td id="f1"><div class="chess_piece white bishop"></div></td>
						<td id="g1"><div class="chess_piece white horse"></div></td>
						<td id="h1"><div class="chess_piece white tower"></div></td>
					</tr>
				</tbody>
			</table>		
		</div><!-- /#gui -->

		<div role="tabpanel" class="tab-pane" id="cli"  >

			<form method="GET" action="/">Command: <input type="text" name="command"/></form>
		</div><!-- /#cli -->
	</div><!-- /.tab-content -->
</div>





<script>
	window.fromCell = "";
	window.toCell = "";
	jQuery('table#board td').on('click', function() {
		if(!$(this).hasClass('selected'))
		{
			// Save the id of the cell clicked
			if (window.fromCell == "")
				window.fromCell = $(this).attr('id');
			else
				window.toCell = $(this).attr('id');

			// Add the styling class ('dashed border')
			$(this).addClass('selected');

			// Wait half a second
			window.setTimeout(function(){
				// 
				if ($('td.selected').length == 2)
				{
					// Action
					// ----------------
					
					// Move the piece
					$('#'+window.fromCell+' div').appendTo($('#'+window.toCell));
					

					$('td.selected').removeClass('selected');
					window.fromCell = "";
					window.toCell = "";
					
				}
			},500);


		}
		else
		{	
			$(this).removeClass('selected');
			window.fromCell = "";
		}
	});
</script>

</body>
</html>
