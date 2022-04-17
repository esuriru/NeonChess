#pragma once
#include "Chesspiece.h"

class Bishop : public ChessPiece {
private:
public:
	Bishop(Colour _c, ChessBoard& ref);
	const std::vector<glm::ivec2>& getPossibleLocations();
};