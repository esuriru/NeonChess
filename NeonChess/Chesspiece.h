#pragma once
#include <glm/glm.hpp>
#include <vector>

enum class Colour { BLACK, WHITE, NIL };
enum class PieceType { PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING, EMPTY };


class ChessPiece {
private:	
	Colour pieceColour;
	PieceType pieceType;
	std::vector<float> piece2DVertices;
public:
	ChessPiece();
	ChessPiece(const Colour& _pc, const PieceType& _pt);
	void setPieceColour(const Colour& colour);
	const Colour& getPieceColour() const;
	void setPieceType(const PieceType type);
	const PieceType& getPieceType() const;
	const std::vector<float> getPieceVertices() const;
	
};