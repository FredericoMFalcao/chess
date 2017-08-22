// Available functions
// -------------------------------------
CHESS_BOARD * clone_board(CHESS_BOARD* base_board);
void initialize_board(CHESS_BOARD * chess_board);
int move_piece(CHESS_BOARD *chess_board, POSITION start, POSITION end, char** error );
void print_board(CHESS_BOARD *chess_board);
void print_board_json(CHESS_BOARD *chess_board);
void print_piece(unsigned int piece, char* text);
void print_piece_css(unsigned int piece, char* text);

void save_board_to_file(char *filename, CHESS_BOARD* board);
void load_board_from_file(char *filename, CHESS_BOARD* board);