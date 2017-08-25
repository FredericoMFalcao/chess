
void parse_command(char *command)
{
	int i;
	POSITION start, end;
	char *error;
	char status_message[1024];

	
	if(strncmp(command, "status",6) == 0)
	{
		output("It's your turn! Type 'move X0 X0' to move one of your pieces.", OUTPUT_MODE_STATUS);
		
		return ;
	}	
	else if(strncmp(command, "move", 4) == 0)
	{
		
		// Check if the coordinates provided are valid		
		if (command[6] > '8' || command[6] < '1' 
			||
			command[5] > 'h' || command[5] < 'a'
			||
			command[9] > '8' || command[9] < '1' 
			||
			command[8] > 'h' || command[8] < 'a' 
			)
		{
			output("ERROR: please use 'move X0 X0' format", OUTPUT_MODE_ERROR);
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
			output("Piece moved!", OUTPUT_MODE_STATUS);

		}			
		// Error
		else if (i == -1)
		{
			output(error,OUTPUT_MODE_ERROR);
			free(error);
		}
		// Successful piece taken
		else
		{
			if ((i & PIECE_COLOR_BIT_MASK ) == WHITE_PIECE)
			{	output("White piece ", OUTPUT_MODE_STATUS); print_piece_css(i, &status_message[0]); output(status_message, OUTPUT_MODE_STATUS); output(" taken.", OUTPUT_MODE_STATUS);}
			
			if ((i & PIECE_COLOR_BIT_MASK ) == BLACK_PIECE)
			{	output("Black piece ", OUTPUT_MODE_STATUS); print_piece_css(i, &status_message[0]); output(status_message, OUTPUT_MODE_STATUS); output(" taken.", OUTPUT_MODE_STATUS);}
			
		}

		if (i != -1)
		{
			// Print the player's current turn:
			// --------------------------------
			if (real_board.current_turn == WHITE_PIECE)
				sprintf(status_message, "It's the %s turn.\n",real_board.player_1);
			
			if (real_board.current_turn == BLACK_PIECE)
				sprintf(status_message, "It's the %s turn.\n",real_board.player_2);
			
			output(status_message, OUTPUT_MODE_STATUS);
			
		}
		
		
		return ;
	}	
	else if(strncmp(command, "print-json", 10) == 0)
	{
		print_board_json(&real_board);
	}	
	else if(strncmp(command, "print", 5) == 0)
	{
		print_board(&real_board);
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
			sprintf(status_message, "Saved to %s\n", &command[5]);
			output(status_message, OUTPUT_MODE_STATUS);
		}
		else
		{	
			save_board_to_file("temp.bin", &real_board);
			sprintf(status_message,"Saved to temp.bin!\n");
			output(status_message, OUTPUT_MODE_STATUS);
		}
	}
	else if(strncmp(command, "reset", 5) == 0)
	{
		initialize_board(&real_board);
		
		sprintf(status_message,"The board has been reset to inital position.");
		output(status_message, OUTPUT_MODE_STATUS);		

	}
	else if(strncmp(command, "possible-moves",14) == 0)
	{
		POSSIBLE_MOVES possible_moves;
		possible_moves.total = 0;
		
		// Check that the coordinates provided are valid		
		if (command[16] > '8' || command[16] < '1' 
			||
			command[15] > 'h' || command[15] < 'a'
			)
		{
			output("ERROR: please use 'possible-moves X0' format", OUTPUT_MODE_ERROR);
			return;
		}
		
		// Convert ASCII to numbers 
		start.row = command[16]-'1';
		start.col = command[15]-'a';

		
		
		if (0) {}
		else if ((real_board.row[start.row].col[start.col] & PIECE_BIT_MASK) == PAWN_PIECE ) 	possible_moves = possible_pawn_move(start, &real_board);
		else if ((real_board.row[start.row].col[start.col] & PIECE_BIT_MASK) == TOWER_PIECE ) 	possible_moves = possible_tower_move(start, &real_board);
		else if ((real_board.row[start.row].col[start.col] & PIECE_BIT_MASK) == HORSE_PIECE ) 	possible_moves = possible_horse_move(start, &real_board);
		else if ((real_board.row[start.row].col[start.col] & PIECE_BIT_MASK) == BISHOP_PIECE )  possible_moves = possible_bishop_move(start, &real_board);
		else if ((real_board.row[start.row].col[start.col] & PIECE_BIT_MASK) == QUEEN_PIECE ) 	possible_moves = possible_queen_move(start, &real_board);
		else if ((real_board.row[start.row].col[start.col] & PIECE_BIT_MASK) == KING_PIECE ) 	possible_moves = possible_king_move(start, &real_board);

		printf("Total possible moves: %d", possible_moves.total);

		for(i = 0; i < possible_moves.total; i++)
		{
			printf("Possible move: %c%c\n", possible_moves.end_position[i].row+'1',possible_moves.end_position[i].col+'a');
		}
		
		
	}
	
	else
	{	
		sprintf(status_message,"Unrecognized command : %s\nType 'quit' to exit.\n",command); 
		output(status_message, OUTPUT_MODE_ERROR);
	}
	
}
