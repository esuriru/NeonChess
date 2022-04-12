#pragma once
#include <array>
#include "Chesspiece.h"

class ChessBoard {
private:
	std::array<ChessPiece, 64> chessboard;

public:
	ChessBoard();
};
