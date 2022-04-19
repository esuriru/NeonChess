#pragma once
#include "Chesspiece.h"

class King : public ChessPiece {
private:
public:
	King(Colour _c, ChessBoard& ref);

	const std::vector<glm::ivec2> getPossibleLocations();

};
