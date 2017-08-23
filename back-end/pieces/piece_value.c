unsigned int piece_value(unsigned int piece)
{
	if (0) {}
	else if ((piece & PIECE_BIT_MASK) == PAWN_PIECE ) 	return PAWN_POINTS;
	else if ((piece & PIECE_BIT_MASK) == TOWER_PIECE ) 	return TOWER_POINTS;
	else if ((piece & PIECE_BIT_MASK) == HORSE_PIECE ) 	return HORSE_POINTS;
	else if ((piece & PIECE_BIT_MASK) == BISHOP_PIECE ) return BISHOP_POINTS;
	else if ((piece & PIECE_BIT_MASK) == QUEEN_PIECE ) 	return QUEEN_POINTS;
	else if ((piece & PIECE_BIT_MASK) == KING_PIECE ) 	return KING_POINTS;
	
	return 0;
	
}