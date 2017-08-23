// Helper function declarations
// ----------------------------
unsigned int is_jumping_over_pieces_horizontally(POSITION start, POSITION end, CHESS_BOARD *chess_board);
unsigned int is_jumping_over_pieces_vertically(POSITION start, POSITION end, CHESS_BOARD *chess_board);
unsigned int is_jumping_over_pieces_diagonally(POSITION start, POSITION end, CHESS_BOARD *chess_board);

// PAWN legal moves
// -----------
unsigned int is_legal_pawn_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error)
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	
	
	// Check if there is an "taking attempt"
	// if the user is trying to move a piece into the opponent's
	// place to take it out
	if (chess_board->row[end.row].col[end.col] & (piece & ~(PIECE_COLOR_BIT_MASK)))
	{
		if ((((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && (end.row - start.row != 1 || abs(end.col - start.col) != 1))
			|| 
			(((piece & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) && (end.row - start.row != -1 || abs(end.col - start.col) != 1))
			)
		{
			*error = (char *)malloc(255);
			sprintf(*error,"ERROR: pawns can only eat one house diagonally forward.\n");
			return 0;			
		}
		
			
	}
	else
	{
		if (chess_board->row[end.row].col[end.col] != 0 )
		{
			*error = (char *)malloc(255);
			sprintf(*error,"ERROR: the destination place is occupied with your piece.\n");
			return 0;
			
		}
		
		if (
			(((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && start.row > 1 && (end.row - start.row) != 1 )
			|| 
			(((piece & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) && start.row == 1 && abs(end.row - start.row) > 2 )
			||
			(((piece & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) && start.row == 6 && abs(end.row - start.row) < -2)
			||
			(end.col != start.col)
			)
		{
			*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Pawns can only move one house forward or exceptionally two houses on their first move.\n");
			return 0;
			
		}
		
		
	}
			
		

/*		if (start.col != end.col && !(chess_board->row[end.row].col[end.col] & BLACK_PIECE))
		{
			*error = (char *)malloc(255);
			sprintf(*error,"ERROR: pawns can only move straight\n");
			return 0;
		}

		if (start.col == end.col && chess_board->row[end.row].col[end.col] & BLACK_PIECE)
		{
			*error = (char *)malloc(255);
			sprintf(*error,"ERROR: pawns cannot eat straight\n");
			return 0;
		}
*/
		
	
		
	return 1;
}

// TOWER legal moves
// -----------
unsigned int is_legal_tower_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error)
{
	int i;
	
	// Check if the move is strictly horizontal or vertical
	if (start.row != end.row && start.col != end.col)
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Tower can only move straight vertically or horizontally\n");
		return 0;
	}
	
	// Check if tower is jumping over any piece


		// If the move is horizontal
		if (start.row == end.row && is_jumping_over_pieces_horizontally(start,end,chess_board))
		{
				*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Tower cannot jump over any piece horizontally.\n");
				return 0;
				
						
		}
		
		// If the move is vertical
		if (start.col == end.col && is_jumping_over_pieces_vertically(start,end,chess_board))
		{
			*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Tower cannot jump over any piece vertically.\n");
			return 0;									
		}
		
		
	
	

	return 1;
}

// HORSE legal moves
// -----------
unsigned int is_legal_horse_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error)
{
	// Horse can move :
	// - 2 up or 2 down and then 1 left or 1 right
	// - 1 up or 1 down and then 2 left or 2 right
	
	// 1st option: 2 up or 2 down and then 1 left or 1 right
	if (abs(end.row - start.row) == 2 && abs(end.col - start.col) == 1)
		return 1;

	// 2nd option: 1 up or 1 down and then 2 left or 2 right
	if (abs(end.row - start.row) == 1 && abs(end.col - start.col) == 2)
		return 1;
	
	
	
	*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Horse can only move in a rotation of letter L\n");
	return 0;
}

// BISHOP legal moves
// -----------
unsigned int is_legal_bishop_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error)
{
	unsigned int i,j;
	
	// Bishop moves diagonally
	if (abs(start.row - end.row) != abs(start.col - end.col))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: bishop can only move diagonally\n");
		return 0;
	}
	
	
	// Check if bishop is moving over any piece
	if (is_jumping_over_pieces_diagonally(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: bishop cannot move over any piece.\n");
		return 0;
		
	}				


	return 1;
}

// QUEEN legal moves
// -----------
unsigned int is_legal_queen_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error)
{
	// Queen can move horizontally or vertically or diagonally
	if (!(start.row == end.row || start.col == end.col || (abs(start.row - end.row) == abs(start.col - end.col))))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Queen can only move horizontally, vertically or diagonally\n");
		return 0;
	}
	
	if (start.row == end.row && is_jumping_over_pieces_horizontally(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Queen cannot jump over pieces [H].\n");
		return 0;
	}
	
	else if (start.col == end.col && is_jumping_over_pieces_vertically(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Queen cannot jump over pieces [V].\n");
		return 0;
	}
	
	else if (abs(start.col - end.col) == abs(start.col - end.col) && is_jumping_over_pieces_diagonally(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: Queen cannot jump over pieces [D].\n");
		return 0;
	}
	

	return 1;
	
}

// KING legal moves
// -----------
unsigned int is_legal_king_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error)
{
	// King can move horizontally or vertically or diagonally one house
	if (!( (start.row == end.row && abs(start.col - end.col) == 1 )
		|| (start.col == end.col && abs(start.row - end.row) == 1)
		|| (abs(start.row - end.row) == 1 && abs(start.col - end.col) == 1)))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: King can only move horizontally, vertically or diagonally one house\n");
		return 0;
	}
	
	if (start.row == end.row && is_jumping_over_pieces_horizontally(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: King cannot jump over pieces [H].\n");
		return 0;
	}
	
	else if (start.col == end.col && is_jumping_over_pieces_vertically(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: King cannot jump over pieces [V].\n");
		return 0;
	}
	
	else if (abs(start.col - end.col) == abs(start.col - end.col) && is_jumping_over_pieces_diagonally(start,end,chess_board))
	{
		*error = (char *)malloc(255);
			sprintf(*error,"ERROR: King cannot jump over pieces [D].\n");
		return 0;
	}
	

	return 1;

	
}


// Helper function
// ----------------------------
unsigned int is_jumping_over_pieces_horizontally(POSITION start, POSITION end, CHESS_BOARD *chess_board)
{
	unsigned int i, j;
	
	for(i = start.col; i != end.col;)
	{
		if (end.col > start.col) i++;
		if (end.col < start.col) i--;	
		
		if (i != end.col && chess_board->row[start.row].col[i] > 0)
			return 1;
	}
	
	return 0;
	
	
}
	
unsigned int is_jumping_over_pieces_vertically(POSITION start, POSITION end, CHESS_BOARD *chess_board)
{
	unsigned int i, j;
	
	for(i = start.row; i != end.row;)
	{
		if (end.row > start.row) i++;
		if (end.row < start.row) i--;	
		
		if (i != end.row && chess_board->row[i].col[start.col] > 0)
		{	
			return 1;
		}
	}
	
	return 0;
	
	
}	

unsigned int is_jumping_over_pieces_diagonally(POSITION start, POSITION end, CHESS_BOARD *chess_board)
{
	unsigned int i, j;
	
	for(i = start.row; i != end.row;)
	{
		if (end.row > start.row) i++;
		if (end.row < start.row) i--;

		for (j = start.col; j != end.col; )
		{
			if (end.col > start.col) j++;
			if (end.col < start.col) j--;
			
			if (chess_board->row[i].col[j] != 0 && i != end.row && j != end.col)
			{
				return 1;
			}
		}
	}

	return 0;
}	