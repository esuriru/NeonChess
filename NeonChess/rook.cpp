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
	for (int i = 0; i < 8; i++) {
		if (boardRef.inBounds(currentLocation + glm::ivec2(0, i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(0, i))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(0, i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(0, i));
			}
			else break;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (boardRef.inBounds(currentLocation + glm::ivec2(0, -i))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(0, -i))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(0, -i)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(0, -i));
			}
			else break;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (boardRef.inBounds(currentLocation + glm::ivec2(i, 0))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(i, 0))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(i, 0)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(i, 0));
			}
			else break;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (boardRef.inBounds(currentLocation + glm::ivec2(-i, 0))) {
			if (boardRef.getPiece(currentLocation + glm::ivec2(-i, 0))->getPieceColour() != this->getPieceColour() || boardRef.getPiece(currentLocation + glm::ivec2(-i, 0)) == nullptr) {
				possibleMoves.push_back(currentLocation + glm::ivec2(-i, 0));
			}
			else break;
		}
	}
	return possibleMoves;
}


