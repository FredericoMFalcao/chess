// 1. Include standard C libraries
// ------------------------
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

// 2. Define structures specific for chess
// ------------------------

// defines a position in the chess board
struct POSITION {int row; int col;};
typedef struct POSITION POSITION;

// defines a chess board row
struct BOARD_ROW {unsigned int col[8]; };
typedef struct BOARD_ROW BOARD_ROW;

// defines a chess board
// - a collection of 8 rows
// - variables for points left for white player
//   black player
// - variables for pieces lost for both players
// - variable to store whose turn it is
struct CHESS_BOARD {
	BOARD_ROW row[8];
	unsigned int white_points;
	unsigned int black_points;
	
	unsigned int lost_white_pieces[16];
	unsigned int lost_black_pieces[16];
	
	unsigned int current_turn;
	
};
typedef struct CHESS_BOARD CHESS_BOARD;

struct POSSIBLE_MOVES {
	unsigned int total;
	POSITION end_position[1024];
	unsigned int points;
};
typedef struct POSSIBLE_MOVES POSSIBLE_MOVES;




// 3. Declare constants
// ------------------------
#define BOTTOM_ROW 0
#define TOP_ROW 7
#define RUNNING_MODE_TEST_1 1


// 4. Declare global variables
// ------------------------
extern unsigned int board[8][8];
extern char player_1[255];
extern char player_2[255];
extern CHESS_BOARD real_board;
extern unsigned int running_mode;

// 5. Declare global functions
// ------------------------
