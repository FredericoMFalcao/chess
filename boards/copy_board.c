// Create a new chess board based on an existing one
//
// useful to create possibilities (simulations) of what would happen
// if a piece moved in a certain direction
// ------------------------------------------------
CHESS_BOARD * clone_board(CHESS_BOARD* base_board)
{
	unsigned int i, j;
	CHESS_BOARD *cloned_board = (CHESS_BOARD *)malloc(sizeof(CHESS_BOARD));
	
	for(i = 0;i<8;i++)
	{
		for (j = 0;j<8; j++)
		{
			cloned_board->row[i].col[j] = base_board->row[i].col[j];
		}
	}
	
	cloned_board->white_points = base_board->white_points;
	cloned_board->black_points = base_board->black_points;
	
	return cloned_board;
}