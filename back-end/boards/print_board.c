void print_piece(unsigned int piece);

void print_board(CHESS_BOARD *chess_board)
{
	int i,j;
	char piece[3];
	
	// Print the current player's turn
	// -------------------------------
	if (chess_board->current_turn == WHITE_PIECE)
		printf("It's the white pieces turn. (%s)\n", chess_board->player_1);
	if (chess_board->current_turn == BLACK_PIECE)
		printf("It's the black pieces turn. (%s)\n", chess_board->player_2);
	
	
	printf("8 |");
	for(i=TOP_ROW;i>=0; i--)
	{
		for(j =0;j<8; j++)
		{	
			// Make the output red in case, it's a hinted move
			if (chess_board->row[i].col[j] & HINTED_PIECE) printf("\033[31m");

			if ((chess_board->row[i].col[j] & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) printf(" w");
			if ((chess_board->row[i].col[j] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) printf(" b");
			

			if (chess_board->row[i].col[j] != 0)
			{
				print_piece(chess_board->row[i].col[j]);
				printf(" |");
			}
			else 
				printf("      ");	
			
			// Reset the output format if it was previously set to red
			if (chess_board->row[i].col[j] & HINTED_PIECE) printf("\033[0m");
			
		}
		if (i>=1)
			printf("\n%d |",i);
	}
	
	// Print the col names
	printf("\n---------------------------------------------------");
	printf("\n  |  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |");
	
	// Include lost pieces
	printf("\nLost white pieces: ");
	for(i = 0;chess_board->lost_white_pieces[i] != 0 && i <= 16; i++)
	{	print_piece(chess_board->lost_white_pieces[i]); printf(" ");}
	
	printf("\nLost black pieces: ");	
	for(i = 0;chess_board->lost_black_pieces[i] != 0 && i <= 16; i++)
	{	print_piece(chess_board->lost_black_pieces[i]);	printf(" ");}
	
	printf("\n");
}

void print_board_json(CHESS_BOARD *chess_board)
{
	int i,j;
	char piece[3];
	
	// Open JSON object
	printf("{");

	// Print the current player's turn
	// -------------------------------
	printf("\"players_turn\":");
	if (chess_board->current_turn == WHITE_PIECE)
		printf("\"white\",");
	if (chess_board->current_turn == BLACK_PIECE)
		printf("\"black\",");

	
	
	printf("\"board\":[");
	for(i=TOP_ROW;i>=0; i--)
	{
		// Start a new row
		printf("[");
		for(j =0;j<8; j++)
		{	

			if ((chess_board->row[i].col[j] & PIECE_COLOR_BIT_MASK) == WHITE_PIECE) printf("\"w");
			if ((chess_board->row[i].col[j] & PIECE_COLOR_BIT_MASK) == BLACK_PIECE) printf("\"b");
			

			if (chess_board->row[i].col[j] != 0)
			{
				print_piece(chess_board->row[i].col[j]);
				printf("\"");
			}
			else 
				printf("\"\"");
			
			if (j<8) printf(",");
			
			
		}
		// end the row
		printf("]");
				
		if (i>=1)
			printf(",");
	}
	// End the board declaration
	printf("]");
		
	// Include lost pieces
	printf(",\"lost_white_pieces\": [");
	for(i = 0;chess_board->lost_white_pieces[i] != 0 && i <= 16; i++)
	{	printf("\""); print_piece(chess_board->lost_white_pieces[i]); printf("\",");}
	
	printf("],\"lost_black_pieces\": [");	
	for(i = 0;chess_board->lost_black_pieces[i] != 0 && i <= 16; i++)
	{	printf("\""); print_piece(chess_board->lost_black_pieces[i]);	printf("\",");}
	printf("]");
	
	// Close JSON object
	printf("}");

}


void print_piece(unsigned int piece)
{
	if (0) {}
	else if ((piece & PIECE_BIT_MASK) == PAWN_PIECE ) printf("PW");
	else if ((piece & PIECE_BIT_MASK) == TOWER_PIECE ) printf("TW");
	else if ((piece & PIECE_BIT_MASK) == HORSE_PIECE ) printf("HR");
	else if ((piece & PIECE_BIT_MASK) == BISHOP_PIECE ) printf("BI");
	else if ((piece & PIECE_BIT_MASK) == QUEEN_PIECE ) printf("QE");
	else if ((piece & PIECE_BIT_MASK) == KING_PIECE ) printf("KI");	
	
	
}