// Helper function declarations
// ----------------------------

// PAWN possible moves
// -----------
POSSIBLE_MOVES possible_pawn_move(POSITION start, CHESS_BOARD* chess_board)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	POSSIBLE_MOVES possible_moves;
	POSITION chess_position;
	possible_moves.total = 0;
	

	// WHITE PIECES
	// -----------------

	// Check if house forward is free
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && start.row > 1 && start.row < 7 && chess_board->row[start.row+1].col[start.col] == 0 )
	{
		chess_position.row = start.row+1;
		chess_position.col = start.col;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

	}

	// Check if pawn is in initial position and two houses forward are free
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && start.row == 1 && chess_board->row[start.row+2].col[start.col] == 0 )
	{
		chess_position.row = start.row+2;
		chess_position.col = start.col;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;


	}

	// Eating possibility one forward one left
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && start.row < 7 && start.col > 0 && (chess_board->row[start.row+1].col[start.col-1] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE )
	{
		chess_position.row = start.row+1;
		chess_position.col = start.col-1;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

		// if filled with a piece from the opposite color
		// add the points of the piece taken
		if ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row+1].col[start.col-1] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
		}

	}

	// Eating possibility one forward one right
	if (((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && start.row < 7 && start.col < 7 && (chess_board->row[start.row+1].col[start.col+1] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE )
	{
		chess_position.row = start.row+1;
		chess_position.col = start.col+1;
		possible_moves.end_position[possible_moves.total] = chess_position;
		possible_moves.total++;

		// if filled with a piece from the opposite color
		// add the points of the piece taken
		if ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) == ((chess_board->row[start.row+1].col[start.col+1] & PIECE_COLOR_BIT_MASK) ^ PIECE_COLOR_BIT_MASK))
		{
			possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
		}

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
			possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
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
			possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
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
				possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
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
				possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
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
				possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
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
				possible_moves.points = chess_board->row[start.row].col[start.col] & PIECE_POINT_VALUE_MASK;
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


// Helper function
// ----------------------------
