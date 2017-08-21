CC=gcc -std=c99
objects = main.o boards.o pieces.o

chess: $(objects)
	$(CC) -o chess $(objects)
	
main.o : main.c main.h hint.c parse_command.c
	$(CC) -c -o main.o main.c

boards.o : boards/main.c boards/boards.h pieces/chess_pieces.h pieces/possible_moves.h pieces/allowed_moves.h main.h boards/print_board.c
	$(CC) -c -o boards.o boards/main.c

pieces.o : pieces/main.c pieces/chess_pieces.h pieces/allowed_moves.c pieces/possible_moves.c main.h
	$(CC) -c -o pieces.o pieces/main.c

verbal_comments.o: verbal_comments/verbal_comments.c verbal_comments/verbal_comments.h main.h
		$(CC) -c -o verbal_comments.o verbal_comments/verbal_comments.c
