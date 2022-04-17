#pragma once
#include <array>
#include "Chesspiece.h"
#include <glm/glm.hpp>
#include <vector>


class ChessPiece;

class ChessBoard {
private:
	std::array<ChessPiece*, 64> chessboard;

public:
	ChessBoard(); //initialize the chessboard
	void setPiece(const glm::ivec2& location, ChessPiece* refPiece);
	ChessPiece*& getPiece(const glm::ivec2& location);
	const glm::ivec2& getPieceLocation(ChessPiece* refPiece) const;
	bool inBounds(const glm::ivec2& location);
};
