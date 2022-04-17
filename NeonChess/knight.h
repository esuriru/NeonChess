#pragma once
#include "Chesspiece.h"

class Knight : public ChessPiece {
private:

public:
	Knight(Colour _c, ChessBoard& ref);
	const std::vector<glm::ivec2>& getPossibleLocations();
};