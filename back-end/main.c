//
// 1. Necessary HEADER files
// -----------------------

#include "main.h"
#include "hint.h" 
#include "pieces/chess_pieces.h"
#include "pieces/possible_moves.h" 
#include "boards/boards.h"


// 2. Declare and Initialize global variables
// ------------------------
unsigned int board[8][8];
char filename[255] = "";
CHESS_BOARD real_board;
unsigned int running_mode = 0;
char load_from_file[255] = "";
char save_to_file[255] = "";
int exec_mode = EXEC_MODE_PROMPT;

char output_buffer[1024] = "";
int output_status;

//
// 3. Other functions in this MODULE
// -----------------------

#include "hint.c"
#include "parse_command.c"





int main(int argc, char**argv)
{
	char *command = NULL;


	size_t command_length = 0;
	
	// Init Strings
	strcpy(&real_board.player_1[0],"white player");
	strcpy(&real_board.player_2[0],"black player");

	// Assign the running mode
	for(int i = 1; i < argc; i++)
	{

		if (strcmp(argv[i],"--test-1") == 0) running_mode |= RUNNING_MODE_TEST_1;		
		if (strncmp(argv[i],"--first-player=",14) == 0) strcpy(real_board.player_1, &argv[i][15]);
		if (strncmp(argv[i],"--second-player=",15) == 0) strcpy(real_board.player_2, &argv[i][16]);
		if (strncmp(argv[i],"--load-from-file=",17) == 0) {strcpy(load_from_file, &argv[i][17]);}
		if (strncmp(argv[i],"--save-to-file=",15) == 0) {strcpy(save_to_file, &argv[i][15]);}
		if (strncmp(argv[i],"--script",8) == 0) {exec_mode = EXEC_MODE_SCRIPT;}
		if (strncmp(argv[i],"--command=",10) == 0) {command = malloc(strlen(argv[i])); strcpy(command, &argv[i][10]);}
		
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
	if (real_board.player_1[0] == 0 && exec_mode != EXEC_MODE_SCRIPT)
	{
		output("\nWhat is the name of the first player? ", OUTPUT_MODE_QUESTION);
		fscanf(stdin,"%s",&real_board.player_1[0]);
	}
	
	if (real_board.player_2[0] == 0 && exec_mode != EXEC_MODE_SCRIPT)
	{
		output("\nWhat is the name of the second player? ", OUTPUT_MODE_QUESTION);
		fscanf(stdin,"%s",&real_board.player_2[0]);
	}
	
	// Load board
	if (filename[0] != 0)
	{
		load_board_from_file(filename, &real_board);
	}
	
	
	// if program is being executed in prompt mode		
	if (exec_mode  == EXEC_MODE_PROMPT)
	{
		output("chess> ", OUTPUT_MODE_STATUS);
		getline(&command,&command_length,stdin);
	
		while(strncmp("quit",command,4) != 0)
		{
			parse_command(command);
		
			output("chess> ", OUTPUT_MODE_STATUS);
			getline(&command,&command_length,stdin);
		
		}
		
		
	}
	
	
	// if program is being executed in script mode
	if (exec_mode == EXEC_MODE_SCRIPT)
	{		
		parse_command(command);
		
		// Flush the output buffer
		// in JSON format
		if (strlen(output_buffer) > 0)
			printf("{\"status\":%d, \"message\":\"%s\"}", output_status, output_buffer);

		// Clear output buffer
		output_buffer[0] = 0;
		
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

void output(char *message, int status)
{
	int i; 
	
	if (exec_mode == EXEC_MODE_SCRIPT)
	{
		// Add space between appended strings
		if (strlen(output_buffer) != 0) sprintf(&output_buffer[strlen(output_buffer)], " ");
		
		// Replace '\n' newline character by ' ' space 
		for(i = 0; i < strlen(message); i++ )
			if (message[i] == '\n') message[i] = ' ';
	
		// Append to output buffer
		sprintf(&output_buffer[strlen(output_buffer)], "%s", message);
		output_status = status;
	}
	
	
	if (exec_mode == EXEC_MODE_PROMPT)
		printf( "%s\n", message);
}
