#pragma once
#include "Chesspiece.h"

class Rook : public ChessPiece {
private:
public:
	Rook(Colour _c, ChessBoard& ref);
	const std::vector<glm::ivec2> getPossibleLocations();
};