#include "Chesspiece.h"

ChessPiece::ChessPiece()
	: pieceColour(Colour::NIL), pieceType(PieceType::EMPTY)
{

}

ChessPiece::ChessPiece(const Colour& _pc, const PieceType& _pt, const glm::ivec2& location) {
	pieceColour = _pc;
	pieceType = _pt;
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