#include "bishop.h"

Bishop::Bishop(Colour _c, ChessBoard& ref)
	: ChessPiece(ref)
{
	pieceColour = _c;
	pieceID = 2;
}

const std::vector<glm::ivec2>& Bishop::getPossibleLocations() {
	glm::ivec2 currentLocation = boardRef.getPieceLocation(this);
	std::vector<glm::ivec2> possibleMoves;
	
	for (int i = 0; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(i, i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(i, i))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(i, i));
			}
			else break;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(i, -i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(i, -i))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(i, -i));
			}
			else break;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(-i, i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(-i, i))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(-i, i));
			}
			else break;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(-i, -i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(-i, -i))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(-i, -i));
			}
			else break;
		}
	}
	return possibleMoves;
}

