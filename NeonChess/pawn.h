#pragma once
#include "Chesspiece.h"

class Pawn : public ChessPiece {
private:
	
public:
	Pawn(Colour _c, ChessBoard& ref);
	const std::vector<glm::ivec2> getPossibleLocations();
};
