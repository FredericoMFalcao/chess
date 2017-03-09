
void hint(CHESS_BOARD *chess_board)
{
	int i,j;
	char letter[9] = "abcdefgh";
	POSSIBLE_MOVES pm;
	POSITION start;
	
	
	start.row = 0;
	start.col = 0;
	pm = possible_tower_move(start,chess_board);
	
	for(i = 0;i<pm.total;i++ )
	{
		printf("a0 %c%d\n",letter[pm.end_position[i].col],pm.end_position[i].row+1);
	}
}
