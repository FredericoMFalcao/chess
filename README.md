![Travis CI Badge](https://travis-ci.org/FredericoMFalcao/chess.svg?branch=master)
![](https://api.keen.io/3.0/projects/58c7b2c30935ce7223c4d8b8/events/page_views?api_key=3E921A47984F4CAE2B3839A4251B348377C5BC1887B9AB1CCE4DD3AFC2A1E7AD74ACF3579905EC7487E192A165195725969678879B31EF1222BBB43DDE15C7E1C2FC78E44830CCA7E89D4AA9B1F32F7497816D6F0A22FA1E9E31DB17CA511322&data=eyJwYWdlIjoibWFpbnBhZ2UifQ==)

#  Chess Game with Artifical Intelligence (AI)

This is a simple chess game written in PHP/C to demontrate and test different AI algorithms the computer can use to test its next move. You can test it online; run it on your web server and play in the browser; or compile it and run and play it in the console.

In the browser you can just click on pieces to direct the next move.
In the console you can see type `print` to check the board state and type `move a2 a3` to move pieces.

A code description on a per-file basis is given below.

### Front-end (/front-end)

-  (index.php) Simple board, chess pieces and AJAX methods to communicate board moves
-  (chess.php) run "chess" back-end.  
	- Convert URL arguments (GET) to console arguments.
	- Print correct server HTTP header (text or JSON)
	- pass correct SESSION string
	
### Back-end (/back-end)

- /boards - defines functions that handle chess boards
	- main.c - includes the relevant files that handle chess boards
	- copy_board.c - clones a board in memory (useful for what-if scenarios)
	- initialize_board.c - sets the pieces in their initial location
	- move_piece.c - attempts to move a piece from one location to another
	- print_board.c - shows the user the state of the board (in text or JSON)
	- save\_load\_from\_file\_ - saves to or loads from a file data into a board
	
- /pieces - defines functions that handle chess pieces
	- main.c - includes the relevant files to handle chess pieces 
	- allowed_moves.c - several functions (one per chess piece type) that determine if a move is valid according to standard chess rules 
	- chess_pieces.h - defines chess pieces type to be used in code
	- possible_moves.c - several functions (one per chess piece type) that list possible moves for a specific piece (useful for computer to try only legal moves)

- (main.c) - Handles program initiation events
	- Handles the commands passed when invoking the program
	- Iniates the board (sets the pieces in the correct location)
	- Asks for user input

- (parse_command.c) - Handles commands passed in the console
	- status - tells the user whose turn it is
	- move - moves a piece from on house to another (including capturing)
	- print-json - shows the board state in json (useful for webservice)
	- print - shows the board state
	- hint - suggest a next move
	- save - saves the board state



## Do you want to test it online?

There is an online demo at (http://chessgame.dtdns.net)


## Do you want to Install it?

### Download it with:
`git clone https://github.com/FredericoMFalcao/chess`

### Compile it with:
`make`

### Run it with:
`./chess`
