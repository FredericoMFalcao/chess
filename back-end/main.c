//
// 1. Necessary HEADER files
// -----------------------

#include "main.h"
#include "hint.h" 
#include "pieces/chess_pieces.h"
#include "pieces/possible_moves.h" 
#include "boards/boards.h"


//
// 2. Other functions in this MODULE
// -----------------------

#include "hint.c"
#include "parse_command.c"
#include "test-1.c"


// 3. Initialize global variables
// ------------------------
unsigned int board[8][8];
char player_1[255] = "";
char player_2[255] = "";
char filename[255] = "";
CHESS_BOARD real_board;
unsigned int running_mode = 0;



int main(int argc, char**argv)
{
	char *command = NULL;


	size_t command_length = 0;
	
	// Init Strings
	player_1[0] = 0;
	player_2[0] = 0;

	// Assign the running mode
	for(int i = 1; i < argc; i++)
	{

		if (strcmp(argv[i],"--test-1") == 0) running_mode |= RUNNING_MODE_TEST_1;		
		if (strncmp(argv[i],"--first-player=",14) == 0) strcpy(&player_1[0], &argv[i][15]);
		if (strncmp(argv[i],"--second-player=",15) == 0) strcpy(&player_2[0], &argv[i][16]);
		if (strncmp(argv[i],"--board-file=",12) == 0) strcpy(&filename[0], &argv[i][13]);
	}


	// Set the piecies in the inital locations
	// acording to standard chess rules
	initialize_board(&real_board);
	
	// Get the player's names
	if (player_1[0] == 0)
	{
		printf("\nWhat is the name of the first player? ");
		fscanf(stdin,"%s",&player_1[0]);
	}
	
	if (player_2[0] == 0)
	{
		printf("\nWhat is the name of the second player? ");
		fscanf(stdin,"%s",&player_2[0]);
	}
	
	// Load board
	if (filename[0] != 0)
	{
		load_board_from_file(filename, &real_board);
	}
		
	
	// Make test 1
	if (running_mode & RUNNING_MODE_TEST_1)
	{
		return test_1();
		
	}		
	
	printf("chess> ");
	getline(&command,&command_length,stdin);
	
	while(strncmp("quit",command,4) != 0)
	{
		parse_command(command);
		
		printf("chess> ");
		getline(&command,&command_length,stdin);
		
	}
	
	
	return 0;
}

void load_board_from_file(char *filename, void *board)
{
	unsigned int i = 0; 
	int c;
	FILE *board_file;

	if (!(board_file = fopen(filename, "r")))
	{	
		printf("ERROR: Could not open board file. %s\n", filename);
	}
	else
	{
		while((c = fgetc(board_file)) != EOF )
		{
			memset(board+i, (char)c,1);
			i++;
		}
		
		fclose(board_file);
	}
	
}

void save_board_to_file(char *filename, void *real_board)
{
	FILE *fp;
	unsigned char c;
	if ((fp = fopen(filename,"w")) == 0)
	{	printf("ERROR: Could not save board state to file : %s", filename);
		return;
	}
	
	for(unsigned int i = 0;  i < sizeof(CHESS_BOARD); i++)
	{
		c = *((char*)&real_board + i);
		printf("val: %d\n", c);
		fputc(c, fp);
	}

	
}


short alpha_numeric(char a)
{
	if ( (a >= 48 && a <= 57 ) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return 1;
	else
		return 0;
}
