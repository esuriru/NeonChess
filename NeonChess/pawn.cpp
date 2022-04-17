#include "pawn.h"

Pawn::Pawn(Colour _c, ChessBoard& ref)
	: ChessPiece(ref)
{
	pieceColour = _c;
	pieceID = 5;
}

const std::vector<glm::ivec2>& Pawn::getPossibleLocations() {
	glm::ivec2 currentLocation = boardRef.getPieceLocation(this);
	std::vector<glm::ivec2> possibleMoves;
	if (this->getPieceColour() == Colour::WHITE) {
		if (boardRef.getPiece(currentLocation + glm::ivec2(0, 1)) == nullptr)
			possibleMoves.push_back(currentLocation + glm::ivec2(0, 1));
		if (currentLocation.y == 1)
			//first move
			possibleMoves.push_back(currentLocation + glm::ivec2(0, 2));
		if (boardRef.getPiece(currentLocation + glm::ivec2(1, 1)) != nullptr && boardRef.getPiece(currentLocation + glm::ivec2(1, 1))->getPieceColour() == Colour::BLACK)
			possibleMoves.push_back(currentLocation + glm::ivec2(1, 1));
		if (boardRef.getPiece(currentLocation + glm::ivec2(-1, 1)) != nullptr && boardRef.getPiece(currentLocation + glm::ivec2(-1, 1))->getPieceColour() == Colour::BLACK)
			possibleMoves.push_back(currentLocation + glm::ivec2(-1, 1));
		return possibleMoves;
	}
	else {
		if (boardRef.getPiece(currentLocation + glm::ivec2(0, -1)) == nullptr)
			possibleMoves.push_back(currentLocation + glm::ivec2(0, -1));
		if (currentLocation.y == 6)
			//first move
			possibleMoves.push_back(currentLocation + glm::ivec2(0, -2));
		if (boardRef.getPiece(currentLocation + glm::ivec2(1, -1)) != nullptr && boardRef.getPiece(currentLocation + glm::ivec2(1, -1))->getPieceColour() == Colour::BLACK)
			possibleMoves.push_back(currentLocation + glm::ivec2(1, -1));
		if (boardRef.getPiece(currentLocation + glm::ivec2(-1, -1)) != nullptr && boardRef.getPiece(currentLocation + glm::ivec2(-1, -1))->getPieceColour() == Colour::BLACK)
			possibleMoves.push_back(currentLocation + glm::ivec2(-1, -1));
		return possibleMoves;
	}
}

