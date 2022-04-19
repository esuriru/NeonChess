#pragma once
#include <array>
#include "Chesspiece.h"
#include <glm/glm.hpp>
#include <vector>


class ChessPiece;
enum class Colour;

class ChessBoard {
private:
	std::array<ChessPiece*, 64> chessboard;
	Colour _ct;

public:
	ChessBoard(); //initialize the chessboard
	void setPiece(const glm::ivec2& location, ChessPiece* refPiece);
	ChessPiece*& getPiece(const glm::ivec2& location);
	const glm::ivec2& getPieceLocation(ChessPiece* refPiece) const;
	bool inBounds(const glm::ivec2& location);
	void movePiece(ChessPiece* _p, const glm::ivec2& location);
	const Colour& getTurn() const;
	void setTurn(const Colour& col);
};
