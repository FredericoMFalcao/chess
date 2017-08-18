

int move_piece(CHESS_BOARD *chess_board, POSITION start, POSITION end, char** error )
{
	unsigned int piece = chess_board->row[start.row].col[start.col];
	unsigned int i;

	int taken_piece = 0;
	
	// Check general piece move rules
	// -----------------------------
	
	
	if (chess_board->row[start.row].col[start.col] == 0)
	{
		*error = (char *)malloc(255);
		sprintf(*error,"ERROR: you're trying to move from an empty place.\n");
		return -1;
	}
	
	if ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) == (chess_board->row[end.row].col[end.col] & PIECE_COLOR_BIT_MASK) )
	{
		*error = (char *)malloc(255);
		sprintf(*error,"ERROR: you're trying to move on top of your pieces.\n");
		return -1;
	}
	
	if (start.row == end.row && start.col == end.col)
	{
		*error = (char *)malloc(255);
		sprintf(*error,"ERROR: you're trying to move the piece into the same place.\n");
		return -1;
	}
	
	if ((chess_board->row[start.row].col[start.col] & PIECE_COLOR_BIT_MASK) != chess_board->current_turn)
	{
		*error = (char *)malloc(255);
		sprintf(*error,"ERROR: you're trying to move your opponent's pieces.\n");
		return -1;				
	}
	
	// Check specific piece's rules
	// -----------------------------
	
	if (((piece & PIECE_BIT_MASK) == PAWN_PIECE) && !is_legal_pawn_move(start, end, chess_board, error))
		return -1;
	
	if (((piece & PIECE_BIT_MASK) == TOWER_PIECE) && !is_legal_tower_move(start, end, chess_board, error))
			return -1;

	if ((piece & PIECE_BIT_MASK) == HORSE_PIECE)
	{
		if (!is_legal_horse_move(start, end, chess_board, error))
			return -1;
	}
	
	if ((piece & PIECE_BIT_MASK) == BISHOP_PIECE)
	{
		if (!is_legal_bishop_move(start, end, chess_board, error))
			return -1;
	}

	if ((piece & PIECE_BIT_MASK) == QUEEN_PIECE)
	{
		if (!is_legal_queen_move(start, end, chess_board, error))
			return -1;
	}
	
	if ((piece & PIECE_BIT_MASK) == KING_PIECE)
	{
		if (!is_legal_king_move(start, end, chess_board, error))
			return -1;
	}
	
	
	
	// Check if a piece was taken
	if (chess_board->row[end.row].col[end.col] > 0)
	{
		// If piece taken was white
		if ((chess_board->row[end.row].col[end.col] & PIECE_COLOR_BIT_MASK) == WHITE_PIECE)
		{
			for(i = 0; i<16;i++)
			{
				// Fill in in the first empty space
				if (chess_board->lost_white_pieces[i] == 0)
				{
					chess_board->lost_white_pieces[i] = chess_board->row[end.row].col[end.col];
					break;
				}
			}
		}
		
		// If piece taken was black
		if ((chess_board->row[end.row].col[end.col] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE)
		{
			for(i = 0; i<16;i++)
			{
				// Fill in in the first empty space
				if (chess_board->lost_black_pieces[i] == 0)
				{
					chess_board->lost_black_pieces[i] = chess_board->row[end.row].col[end.col];
					break;
				}
			}
		}
		
		// Assign the taken piece
		taken_piece = chess_board->row[end.row].col[end.col];
		
	}

	// Move the actual piece in the board	
	chess_board->row[end.row].col[end.col] = chess_board->row[start.row].col[start.col];
	chess_board->row[start.row].col[start.col] = 0;
	
	// Switch the turn
	chess_board->current_turn ^=  WHITE_PIECE;
	chess_board->current_turn ^=  BLACK_PIECE;

	return taken_piece;
}

