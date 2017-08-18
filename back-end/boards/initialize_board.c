
// Set all the pieces in the right places
// according to standard chess rules
void initialize_board(CHESS_BOARD * chess_board)
{
	// 0. Set emtpy spaces
	// -------------------
	for(int i=TOP_ROW;i>=0; i--)
		for(int j =0;j<8; j++)
			chess_board->row[i].col[j] = 0;
	
	// 1. Set the white pieces       
	// -----------------------       
	chess_board->row[BOTTOM_ROW].col[0] = WHITE_PIECE  |  TOWER_PIECE  |  TOWER_VALUE;  
	chess_board->row[BOTTOM_ROW].col[1] = WHITE_PIECE  |  HORSE_PIECE  |  HORSE_VALUE;  
	chess_board->row[BOTTOM_ROW].col[2] = WHITE_PIECE  |  BISHOP_PIECE  |  BISHOP_VALUE;  
	chess_board->row[BOTTOM_ROW].col[3] = WHITE_PIECE  |  QUEEN_PIECE  |  QUEEN_VALUE;  
	chess_board->row[BOTTOM_ROW].col[4] = WHITE_PIECE  |  KING_PIECE  |  KING_VALUE;  
	chess_board->row[BOTTOM_ROW].col[5] = WHITE_PIECE  |  BISHOP_PIECE  |  BISHOP_VALUE;  
	chess_board->row[BOTTOM_ROW].col[6] = WHITE_PIECE  |  HORSE_PIECE  |  HORSE_VALUE;  
	chess_board->row[BOTTOM_ROW].col[7] = WHITE_PIECE  |  TOWER_PIECE  |  TOWER_VALUE;  

	chess_board->row[BOTTOM_ROW+1].col[0] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[1] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[2] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[3] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[4] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[5] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[6] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  
	chess_board->row[BOTTOM_ROW+1].col[7] = WHITE_PIECE  |  PAWN_PIECE  |  PAWN_VALUE;  


	// 2. Set the black pieces       
	// -----------------------       
	chess_board->row[TOP_ROW].col[0] = BLACK_PIECE  |  TOWER_PIECE |  TOWER_VALUE;  
	chess_board->row[TOP_ROW].col[1] = BLACK_PIECE  |  HORSE_PIECE |  HORSE_VALUE;  
	chess_board->row[TOP_ROW].col[2] = BLACK_PIECE  |  BISHOP_PIECE |  BISHOP_VALUE;  
	chess_board->row[TOP_ROW].col[3] = BLACK_PIECE  |  QUEEN_PIECE |  QUEEN_VALUE;  
	chess_board->row[TOP_ROW].col[4] = BLACK_PIECE  |  KING_PIECE |  KING_VALUE;  
	chess_board->row[TOP_ROW].col[5] = BLACK_PIECE  |  BISHOP_PIECE |  BISHOP_VALUE;  
	chess_board->row[TOP_ROW].col[6] = BLACK_PIECE  |  HORSE_PIECE |  HORSE_VALUE;  
	chess_board->row[TOP_ROW].col[7] = BLACK_PIECE  |  TOWER_PIECE |  TOWER_VALUE;  

	chess_board->row[TOP_ROW-1].col[0] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[1] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[2] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[3] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[4] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[5] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[6] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  
	chess_board->row[TOP_ROW-1].col[7] = BLACK_PIECE  |  PAWN_PIECE |  PAWN_VALUE;  



	// 3. Set the lost pieces to empty
	// -----------------------	
	memset(chess_board->lost_white_pieces,0,16*sizeof(unsigned int));
	memset(chess_board->lost_black_pieces,0,16*sizeof(unsigned int));
	
	// 4. Set the current turn to white player
	// -----------------------	
	chess_board->current_turn = WHITE_PIECE;
}