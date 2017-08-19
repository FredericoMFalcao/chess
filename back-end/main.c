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
char player_1[255];
char player_2[255];
CHESS_BOARD real_board;
unsigned int running_mode = 0;
int board_loaded = 0;






int main(int argc, char**argv)
{
	char *command = NULL;

	size_t command_length = 0;

	// Assign the running mode
	for(int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i],"--test-1") == 0) running_mode |= RUNNING_MODE_TEST_1;		
		if (strncmp(argv[i],"--load-from-file=",17) == 0) {load_board_from_file(&argv[i][17], &real_board); board_loaded = 1;}
	}


	// Set the piecies in the inital locations
	// acording to standard chess rules
	if (!board_loaded)
	{
		initialize_board(&real_board);
		board_loaded = 1;
	}
	
	// Get the player's names
	printf("\nWhat is the name of the first player? ");
	fscanf(stdin,"%s",&player_1[0]);
	

	printf("\nWhat is the name of the second player? ");
	fscanf(stdin,"%s",&player_2[0]);
		
	
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




short alpha_numeric(char a)
{
	if ( (a >= 48 && a <= 57 ) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return 1;
	else
		return 0;
}
