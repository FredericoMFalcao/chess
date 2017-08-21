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



// 3. Initialize global variables
// ------------------------
unsigned int board[8][8];
char player_1[255] = "";
char player_2[255] = "";
char filename[255] = "";
CHESS_BOARD real_board;
unsigned int running_mode = 0;
char load_from_file[255] = "";
char save_to_file[255] = "";
int exec_mode = EXEC_MODE_PROMPT;



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
		if (strncmp(argv[i],"--load-from-file=",17) == 0) {strcpy(load_from_file, &argv[i][17]);}
		if (strncmp(argv[i],"--save-to-file=",15) == 0) {strcpy(save_to_file, &argv[i][15]);}
		if (strncmp(argv[i],"--script",8) == 0) {exec_mode = EXEC_MODE_SCRIPT;}
	}


	// Set the piecies in the inital locations
	// acording to standard chess rules
	if (load_from_file[0] == 0)
	{
		initialize_board(&real_board);
	}
	else
	{
		load_board_from_file(load_from_file, &real_board);
	}
	
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
	
	
	// if program is being executed in prompt mode		
	if (exec_mode  == EXEC_MODE_PROMPT)
	{
		printf("chess> ");
		getline(&command,&command_length,stdin);
	
		while(strncmp("quit",command,4) != 0)
		{
			parse_command(command);
		
			printf("chess> ");
			getline(&command,&command_length,stdin);
		
		}
		
		
	}
	
	
	// if program is being executed in script mode
	if (exec_mode == EXEC_MODE_SCRIPT)
	{
		
		while(getline(&command,&command_length,stdin) > 0)
		{
			parse_command(command);
		}						
		
	}

	// If argument provided --save-to-file
	// save the board to binary file before 
	// quitting
	if (save_to_file[0] != 0)
	{
		save_board_to_file(save_to_file, &real_board);
		
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
