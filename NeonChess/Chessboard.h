#pragma once
#include <array>
#include "Chesspiece.h"
#include <glm/glm.hpp>

class ChessBoard {
private:
	std::array<ChessPiece*, 64> chessboard;

public:
	ChessBoard(); //initialize the chessboard
	void setPiece(const glm::ivec2& location, ChessPiece* refPiece);
	ChessPiece*& getPiece(const glm::ivec2& location);

};
