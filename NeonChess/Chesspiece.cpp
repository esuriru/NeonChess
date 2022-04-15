#include "Chesspiece.h"

ChessPiece::ChessPiece()
	: pieceColour(Colour::NIL), pieceType(PieceType::EMPTY)
{
	
}


ChessPiece::ChessPiece(const Colour& _pc, const PieceType& _pt) {
	pieceColour = _pc;
	pieceType = _pt;
	piece2DVertices = {
		0.5f, -0.5f, 0.0f,
		0.0f, -0.5f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f
	};
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

const std::vector<float> ChessPiece::getPieceVertices() const
{
	return piece2DVertices;
}



