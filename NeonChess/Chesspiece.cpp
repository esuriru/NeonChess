#include "Chesspiece.h"

ChessPiece::ChessPiece(const glm::ivec2& location)
	: pieceColour(Colour::NIL), pieceType(PieceType::EMPTY)
{
	pieceLocation = location;
}

ChessPiece::ChessPiece(const Colour& _pc, const PieceType& _pt, const glm::ivec2& location) {
	pieceColour = _pc;
	pieceType = _pt;
	pieceLocation = location;
}

const glm::ivec2& ChessPiece::getPieceLocation() const {
	return pieceLocation;
}

void ChessPiece::setPieceLocation(const glm::ivec2& location) {
	pieceLocation = location;
}

void ChessPiece::setPieceColour(const Colour& colour) {
	pieceColour = colour;
}
const Colour& ChessPiece::getPieceColour() const {
	return pieceColour;
}

void ChessPiece::setPieceType(const PieceType type) {
	pieceType = type;
}
const PieceType& ChessPiece::getPieceType() const {
	return pieceType;
}