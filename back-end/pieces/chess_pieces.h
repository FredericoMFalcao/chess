// All chess piesces and numeric ids
// -------------------------------------
#define PAWN_PIECE 		1
#define TOWER_PIECE 	2
#define HORSE_PIECE 	3
#define BISHOP_PIECE 	4
#define QUEEN_PIECE 	5
#define KING_PIECE	 	6

#define PIECE_BIT_MASK	7

#define WHITE_PIECE 8
#define BLACK_PIECE 16
#define PIECE_COLOR_BIT_MASK (8+16)

#define HINTED_PIECE 32

// Chess pieces values
// -------------------------------------

#define PAWN_VALUE		64
#define TOWER_VALUE 	256
#define HORSE_VALUE 	128
#define BISHOP_VALUE 	256
#define QUEEN_VALUE		512
#define KING_VALUE		1024

#define PIECE_POINT_VALUE_MASK (64+128+256+512+1024)
