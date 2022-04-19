#include "knight.h"

Knight::Knight(Colour _c, ChessBoard& ref)
	: ChessPiece(ref)
{
	pieceColour = _c;
	pieceID = 3;
}

const std::vector<glm::ivec2> Knight::getPossibleLocations() {
	glm::ivec2 currentLocation = boardRef.getPieceLocation(this);
	std::vector<glm::ivec2> possibleMoves;
	possibleMoves.push_back(currentLocation + glm::ivec2(1, 2));
	possibleMoves.push_back(currentLocation + glm::ivec2(-1, 2));
	possibleMoves.push_back(currentLocation + glm::ivec2(1, -2));
	possibleMoves.push_back(currentLocation + glm::ivec2(-1, -2));
	possibleMoves.push_back(currentLocation + glm::ivec2(2, 1));
	possibleMoves.push_back(currentLocation + glm::ivec2(-2, 1));
	possibleMoves.push_back(currentLocation + glm::ivec2(2, -1));
	possibleMoves.push_back(currentLocation + glm::ivec2(-2, -1));

	for (int i = 0; i < possibleMoves.size(); i++) {
		if (!(boardRef.inBounds(possibleMoves[i])))
			possibleMoves.erase(possibleMoves.begin() + i);
	}

	return possibleMoves;
}
