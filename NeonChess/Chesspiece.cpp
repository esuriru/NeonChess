#include "Chesspiece.h"




ChessPiece::ChessPiece(ChessBoard& ref)
	: boardRef(ref)
{

}

void ChessPiece::setPieceColour(const Colour& colour) {
	pieceColour = colour;
}
const Colour& ChessPiece::getPieceColour() const {
	return pieceColour;
}


const unsigned int& ChessPiece::getPieceID() const
{
	return pieceID;
}



