// Helper function declarations
// ----------------------------

// PAWN legal moves
// -----------
unsigned int is_legal_pawn_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error);

// TOWER legal moves
// -----------
unsigned int is_legal_tower_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error);

// HORSE legal moves
// -----------
unsigned int is_legal_horse_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error);

// BISHOP legal moves
// -----------
unsigned int is_legal_bishop_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error);

// QUEEN legal moves
// -----------
unsigned int is_legal_queen_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error);

// KING legal moves
// -----------
unsigned int is_legal_king_move(POSITION start, POSITION end, CHESS_BOARD *chess_board, char** error);


