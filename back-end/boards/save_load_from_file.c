void save_board_to_file(char *filename, CHESS_BOARD* board)
{
	FILE *fp;
	if (!(fp = fopen(filename, "wb")))
	{	
		printf("ERROR: Could not open file for write mode. (%s)", filename);
		return;
	}
	
	fwrite(board, sizeof(CHESS_BOARD),1, fp);
	fclose(fp);
}

void load_board_from_file(char *filename, CHESS_BOARD* board)
{
	FILE *fp;
	if (!(fp = fopen(filename, "rb")))
	{	
		printf("ERROR: Could not open file for read mode. (%s)", filename);
		return;
	}
	
	fread(board, sizeof(CHESS_BOARD),1, fp);
	fclose(fp);
}
