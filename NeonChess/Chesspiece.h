#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Chessboard.h"


class ChessBoard;
enum class Colour { BLACK, WHITE };



class ChessPiece {
protected:	
	unsigned int pieceID;
	Colour pieceColour;
	ChessBoard& boardRef;

public:
	ChessPiece(ChessBoard& ref);
	void setPieceColour(const Colour& colour);
	const Colour& getPieceColour() const;
	virtual const std::vector<glm::ivec2>& getPossibleLocations() = 0;
	const unsigned int& getPieceID() const;
	
};