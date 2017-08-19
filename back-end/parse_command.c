
void parse_command(char *command)
{
	int i;
	POSITION start, end;
	char *error;

	
	if(strcmp(command, "status") == 0)
	{
		printf("It's your turn! Type 'move X0 X0' to move one of your pieces.\n");
		
		return ;
	}
	
	else if(strncmp(command, "move", 4) == 0)
	{
		
		if (command[6] > '8' || command[6] < '1' 
			||
			command[5] > 'h' || command[5] < 'a'
			||
			command[9] > '8' || command[9] < '1' 
			||
			command[8] > 'h' || command[8] < 'a' 
			)
		{
			printf("ERROR: please use 'move X0 X0' format\n");
			return;
		}
		
		// Convert ASCII to numbers 
		start.row = command[6]-'1';
		start.col = command[5]-'a';

		end.row = command[9]-'1';
		end.col = command[8]-'a';
		
		i = move_piece(&real_board,start, end, &error);

		// Successful move
		if (i == 0)
		{
//			no_action_phrase();
			printf("Moved!");
		}			
		// Error
		else if (i == -1)
		{
			printf("%s",error);
			free(error);
		}
		// Successful piece taken
		else
		{
			if ((i & PIECE_COLOR_BIT_MASK ) == WHITE_PIECE)
			{	printf("White piece "); print_piece(i); printf(" taken.\n");}
			
			if ((i & PIECE_COLOR_BIT_MASK ) == BLACK_PIECE)
			{	printf("Black piece "); print_piece(i); printf(" taken.\n");}
			
		}

		if (i != -1)
		{
			// Print the player's current turn:
			// --------------------------------
			if (real_board.current_turn == WHITE_PIECE)
				printf("It's the %s turn.\n",&player_1[0]);
			if (real_board.current_turn == BLACK_PIECE)
				printf("It's the %s turn.\n",&player_2[0]);				
			
		}
				
		
		
		
		return ;
	}
	
	else if(strncmp(command, "print", 5) == 0)
	{
		print_board(&real_board);
	}
	else if(strncmp(command, "print-json", 10) == 0)
	{
		print_board_json(&real_board);
	}	
	
	else if(strncmp(command, "hint", 4) == 0)
	{
		hint(&real_board);
	}
	else if(strncmp(command, "save", 4) == 0)
	{
		if(strncmp(command, "save ", 5) == 0)
		{
			
			// Discard 'newline' character
			for(int i=0; i < strlen(command); i++)
				if (command[i] == '\n') command[i] = 0;
			
			save_board_to_file(&command[5], &real_board);
			printf("Saved to %s\n", &command[5]);
		}
		else
		{	
			save_board_to_file("temp.bin", &real_board);
			printf("Saved to temp.bin!\n");
		}
	}
	
	else
		printf("Unrecognized command : %s\nType 'quit' to exit.\n",command); 
	
}
