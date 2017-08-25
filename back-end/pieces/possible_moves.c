// Helper function declarations
// ----------------------------

void add_possible_move(const POSITION *pos, POSSIBLE_MOVES *possible_moves);

void sum_possible_move_points(unsigned int points, POSSIBLE_MOVES *possible_moves);

// PAWN possible moves
// -----------
POSSIBLE_MOVES possible_pawn_move(POSITION start, CHESS_BOARD* chess_board)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSITION chess_position;
	
	// Declare and init POSSIBLE_MOVES
	POSSIBLE_MOVES possible_moves;
	possible_moves.total = 0;
	

	// WHITE PIECES
	// -----------------

	// Check if house forward is free
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) /* piece is white */
		&& start.row > 1 /* piece is not in the initial position */
		&& start.row < 7 /* piece is not in the final, conversion position */
		&& chess_board->row[start.row+1].col[start.col] == 0 /* house in front is free */
		)
	{
		chess_position.row = start.row+1;
		chess_position.col = start.col;
		add_possible_move(&chess_position, &possible_moves);

	}

	// Check if pawn is in initial position and two houses forward are free
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) /* piece is white */
		&& start.row == 1 /* piece is in its initial position */
		&& chess_board->row[start.row+2].col[start.col] == 0 /* two houses ahead is free */
		)
	{
		chess_position.row = start.row+2;
		chess_position.col = start.col;
		add_possible_move(&chess_position, &possible_moves);

	}

	// Eating possibility one forward one left
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) /* piece is white */
		&& start.row < 7 /* piece is not in the final row */
		&& start.col > 0 /* piece is not "misteriously" in the first row */
		&& (chess_board->row[start.row+1].col[start.col-1] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE /* piece in front right is black */
		)
	{
		// Add end position to the list
		chess_position.row = start.row+1;
		chess_position.col = start.col-1;		
		add_possible_move(&chess_position, &possible_moves);

		// Add the points the player would get
		// by taking this piece
		sum_possible_move_points(piece_value(chess_board->row[start.row+1].col[start.col-1]), &possible_moves);

	}

	// Eating possibility one forward one right
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) /* piece is white */
		&& start.row < 7 /* piece is not in the last row */
		&& start.col < 7 /* piece is not in the right-most column */
		&& (chess_board->row[start.row+1].col[start.col+1] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE /* piece in front right is black */
		)
	{
		// Add end position to the list
		chess_position.row = start.row+1;
		chess_position.col = start.col+1;
		add_possible_move(&chess_position, &possible_moves);

		// Add the points the player would get
		// by taking this piece
		sum_possible_move_points(piece_value(chess_board->row[start.row+1].col[start.col+1]), &possible_moves);
		
	}
		

	// BLACK PIECES
	// -----------------

	// Check if house forward is free
	if (((piece & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) && start.row < 6 && start.row > 0 && chess_board->row[start.row-1].col[start.col] == 0 )
	{
		chess_position.row = start.row-1;
		chess_position.col = start.col;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

	}

	// Check if pawn is in initial position and two houses forward are free
	if (((piece & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) && start.row == 6 && chess_board->row[start.row-2].col[start.col] == 0 )
	{
		chess_position.row = start.row-2;
		chess_position.col = start.col;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

	}

	// Eating possibility one forward one left
	if (((piece & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) && start.row > 0 && start.col > 0 && (chess_board->row[start.row-1].col[start.col-1] & PIECE_COLOR_BIT_MASK) == WHITE_PIECE )
	{
		chess_position.row = start.row-1;
		chess_position.col = start.col-1;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

		// if filled with a piece from the opposite color
		// add the points of the piece taken
		if ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row+1].col[start.col-1] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			possible_moves.points = chess_board->row[start.row].col[start.col] & POSSIBLE_MOVE_PIECE;
		}

	}

	// Eating possibility one forward one right
	if (((piece & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) && start.row > 0 && start.col < 7 && (chess_board->row[start.row-1].col[start.col+1] & PIECE_COLOR_BIT_MASK) == WHITE_PIECE )
	{
		chess_position.row = start.row-1;
		chess_position.col = start.col+1;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

		// if filled with a piece from the opposite color
		// add the points of the piece taken
		if ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row-1].col[start.col+1] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			possible_moves.points = chess_board->row[start.row].col[start.col] & POSSIBLE_MOVE_PIECE;
		}

	}
	
		
	return possible_moves;
}

// TOWER possible moves
// -----------
POSSIBLE_MOVES possible_tower_move(POSITION start, CHESS_BOARD* chess_board)
{
	int i;
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSSIBLE_MOVES possible_moves;
	POSITION chess_position;
	possible_moves.total = 0;
	possible_moves.points = 0;
	

	// Horizontally
	// -----------------

	// Horizontally left
	for(i = start.col-1;i>=0;i--)
	{
		
		// If house is empty, or is filled with a piece from the opposite color
		// add as a possible move
		if (chess_board->row[start.row].col[i] == 0 
			|| (chess_board->row[start.row].col[i] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			chess_position.row = start.row;
			chess_position.col = i;
			possible_moves.end_position[possible_moves.total] = chess_position;
			possible_moves.total++;
			
			// if filled with a piece from the opposite color
			// add the points of the piece taken
			if ((chess_board->row[start.row].col[i] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
			{
				possible_moves.points = chess_board->row[start.row].col[start.col] & POSSIBLE_MOVE_PIECE;
			}
		}
		// Prevent jumping over pieces
		else
			break;
		
	}


	// Horizontally right
	for(i = start.col+1;i<=7;i++)
	{
		// If house is empty, or is filled with a piece from the opposite color
		// add as a possible move
		if (chess_board->row[start.row].col[i] == 0 
			|| (chess_board->row[start.row].col[i] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			chess_position.row = start.row;
			chess_position.col = i;
			possible_moves.end_position[possible_moves.total] = chess_position;
			possible_moves.total++;
			// if filled with a piece from the opposite color
			// add the points of the piece taken
			if ((chess_board->row[start.row].col[i] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
			{
				possible_moves.points = chess_board->row[start.row].col[start.col] & POSSIBLE_MOVE_PIECE;
			}

		}
		// Prevent jumping over pieces
		else
			break;
		
	}
	
	// Vertically
	// -----------------

	// Vertical down
	for(i = start.row-1;i>=0;i--)
	{
		// If house is empty, or is filled with a piece from the opposite color
		// add as a possible move
		if (chess_board->row[i].col[start.col] == 0 
			|| (chess_board->row[i].col[start.col] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			chess_position.row = i;
			chess_position.col = start.col;
			possible_moves.end_position[possible_moves.total] = chess_position;
			possible_moves.total++;
			// if filled with a piece from the opposite color
			// add the points of the piece taken
			if ((chess_board->row[start.row].col[i] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
			{
				possible_moves.points = chess_board->row[start.row].col[start.col] & POSSIBLE_MOVE_PIECE;
			}

		}
		// Prevent jumping over pieces
		else
			break;
		
	}


	// Vertical up
	for(i = start.row+1;i<=7;i++)
	{
		// If house is empty, or is filled with a piece from the opposite color
		// add as a possible move
		if (chess_board->row[i].col[start.col] == 0 
			|| (chess_board->row[i].col[start.col] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			chess_position.row = i;
			chess_position.col = start.col;
			possible_moves.end_position[possible_moves.total] = chess_position;
			possible_moves.total++;
			// if filled with a piece from the opposite color
			// add the points of the piece taken
			if ((chess_board->row[start.row].col[i] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
			{
				possible_moves.points = chess_board->row[start.row].col[start.col] & POSSIBLE_MOVE_PIECE;
			}

		}
		// Prevent jumping over pieces
		else
			break;
		
	}
	
		
	return possible_moves;
}
	
// HORSE possible moves
// -----------
POSSIBLE_MOVES possible_horse_move(POSITION start, CHESS_BOARD* chess_board)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSSIBLE_MOVES possible_moves;
	POSITION chess_position;
	possible_moves.total = 0;

	
		
	return possible_moves;
}

// BISHOP possible moves
// -----------
POSSIBLE_MOVES possible_bishop_move(POSITION start, CHESS_BOARD* chess_board)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSSIBLE_MOVES possible_moves;
	POSITION chess_position;
	possible_moves.total = 0;

	
		
	return possible_moves;
}

// QUEEN possible moves
// -----------
POSSIBLE_MOVES possible_queen_move(POSITION start, CHESS_BOARD* chess_board)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSSIBLE_MOVES possible_moves;
	POSITION chess_position;
	possible_moves.total = 0;

	
		
	return possible_moves;
}

// KING possible moves
// -----------
POSSIBLE_MOVES possible_king_move(POSITION start, CHESS_BOARD* chess_board)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSSIBLE_MOVES possible_moves;
	POSITION chess_position;
	possible_moves.total = 0;

	
		
	return possible_moves;
}




// Helper function definition
// ----------------------------
void add_possible_move(const POSITION *pos, POSSIBLE_MOVES *possible_moves)
{
	possible_moves->end_position[possible_moves->total] = *pos;
	possible_moves->total++;
}

void sum_possible_move_points(unsigned int points, POSSIBLE_MOVES *possible_moves)
{
	possible_moves->points += points;
}
