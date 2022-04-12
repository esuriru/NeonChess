#pragma once
#include <glm/glm.hpp>

enum class Colour { BLACK, WHITE, NIL };
enum class PieceType { PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING, EMPTY };

class ChessPiece {
private:	
	Colour pieceColour;
	PieceType pieceType;
public:
	ChessPiece();
	ChessPiece(const Colour& _pc, const PieceType& _pt, const glm::ivec2& location);
	void setPieceColour(const Colour& colour);
	const Colour& getPieceColour() const;
	void setPieceType(const PieceType type);
	const PieceType& getPieceType() const;

};