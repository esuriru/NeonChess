#pragma once
#include <glm/glm.hpp>

enum class Colour { BLACK, WHITE, NIL };
enum class PieceType { PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING, EMPTY };

class ChessPiece {
private:
	glm::ivec2 pieceLocation;
	Colour pieceColour;
	PieceType pieceType;
public:
	ChessPiece(const glm::ivec2& location);
	ChessPiece(const Colour& _pc, const PieceType& _pt, const glm::ivec2& location);
	void setPieceLocation(const glm::ivec2& location);
	const glm::ivec2& getPieceLocation() const;
	void setPieceColour(const Colour& colour);
	const Colour& getPieceColour() const;
	void setPieceType(const PieceType type);
	const PieceType& getPieceType() const;

};