
void hint(CHESS_BOARD *chess_board)
{
	int i,j;
	char letter[9] = "abcdefgh";
	char status_message[255];
	POSSIBLE_MOVES pm;
	POSITION start;
	
	
	start.row = 0;
	start.col = 0;
	pm = possible_tower_move(start,chess_board);
	
	for(i = 0;i<pm.total;i++ )
	{
		sprintf(status_message, "a0 %c%d\n",letter[pm.end_position[i].col],pm.end_position[i].row+1);
		output(status_message, OUTPUT_MODE_STATUS);
	}
}
