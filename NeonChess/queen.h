#pragma once
#include "Chesspiece.h"

class Queen : public ChessPiece {
private:
public:
	Queen(Colour _c, ChessBoard& ref);

	const std::vector<glm::ivec2> getPossibleLocations();

};
