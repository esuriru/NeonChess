#include "rook.h"

Rook::Rook(Colour _c, ChessBoard& ref)
	: ChessPiece(ref)
{
	pieceColour = _c;
	pieceID = 4;
}

const std::vector<glm::ivec2> Rook::getPossibleLocations() {
	glm::ivec2 currentLocation = boardRef.getPieceLocation(this);
	std::vector<glm::ivec2> possibleMoves;
	for (int i = 1; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(0, i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(0, i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(0, i));
				continue;
			}
			else if (boardRef.getPiece(currentLocation + glm::ivec2(0, i))->getPieceColour() != this->getPieceColour()) {
				possibleMoves.push_back(currentLocation + glm::ivec2(0, i));
				break;
			}
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(0, -i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(0, -i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(0, -i));
				continue;
			}
			else if (boardRef.getPiece(currentLocation + glm::ivec2(0, -i))->getPieceColour() != this->getPieceColour()) {
				possibleMoves.push_back(currentLocation + glm::ivec2(0, -i));
				break;
			}
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{

		if (boardRef.inBounds(currentLocation + glm::ivec2(i, 0))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(i, 0)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(i, 0));
				continue;
			}
			else if (boardRef.getPiece(currentLocation + glm::ivec2(i, 0))->getPieceColour() != this->getPieceColour()) {
				possibleMoves.push_back(currentLocation + glm::ivec2(i, 0));
				break;
			}
			else break;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (boardRef.inBounds(currentLocation + glm::ivec2(-i, 0))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(-i, 0)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(-i, 0));
				continue;
			}
			else if (boardRef.getPiece(currentLocation + glm::ivec2(-i, 0))->getPieceColour() != this->getPieceColour()) {
				possibleMoves.push_back(currentLocation + glm::ivec2(-i, 0));
				break;
			}
			else break;
		}
	}
	return possibleMoves;
}


