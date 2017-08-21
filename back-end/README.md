## Back-end

Code documentation per-file:

- [/boards](https://github.com/FredericoMFalcao/chess/tree/master/back-end/boards) - defines functions that handle chess boards
	- main.c - includes the relevant files that handle chess boards
	- copy_board.c - clones a board in memory (useful for what-if scenarios)
	- initialize_board.c - sets the pieces in their initial location
	- move_piece.c - attempts to move a piece from one location to another
	- print_board.c - shows the user the state of the board (in text or JSON)
	- save\_load\_from\_file\_ - saves to or loads from a file data into a board
	
- [/pieces](https://github.com/FredericoMFalcao/chess/tree/master/back-end/pieces) - defines functions that handle chess pieces
	- main.c - includes the relevant files to handle chess pieces 
	- allowed_moves.c - several functions (one per chess piece type) that determine if a move is valid according to standard chess rules 
	- chess_pieces.h - defines chess pieces type to be used in code
	- possible_moves.c - several functions (one per chess piece type) that list possible moves for a specific piece (useful for computer to try only legal moves)

- ([main.c](https://github.com/FredericoMFalcao/chess/blob/master/back-end/main.c)) - Handles program initiation events
	- Handles the commands passed when invoking the program
	- Iniates the board (sets the pieces in the correct location)
	- Asks for user input

- ([parse_command.c](https://github.com/FredericoMFalcao/chess/blob/master/back-end/parse_command.c)) - Handles commands passed in the console
	- status - tells the user whose turn it is
	- move - moves a piece from on house to another (including capturing)
	- print-json - shows the board state in json (useful for webservice)
	- print - shows the board state
	- hint - suggest a next move
	- save - saves the board state
