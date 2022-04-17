#include "king.h"

King::King(Colour _c, ChessBoard& ref)
	: ChessPiece(ref)
{
	pieceColour = _c;	
	pieceID = 0;
}

const std::vector<glm::ivec2>& King::getPossibleLocations() {
	glm::ivec2 currentLocation = boardRef.getPieceLocation(this);
	std::vector<glm::ivec2> possibleMoves;
	possibleMoves.push_back(currentLocation + glm::ivec2(0, 1));
	possibleMoves.push_back(currentLocation + glm::ivec2(0, -1));
	possibleMoves.push_back(currentLocation + glm::ivec2(1, 1));
	possibleMoves.push_back(currentLocation + glm::ivec2(1, -1));
	possibleMoves.push_back(currentLocation + glm::ivec2(-1, 1));
	possibleMoves.push_back(currentLocation + glm::ivec2(-1, -1));
	possibleMoves.push_back(currentLocation + glm::ivec2(1, 0));
	possibleMoves.push_back(currentLocation + glm::ivec2(-1, 0));
	//cleanup
	for (int i = 0; i < possibleMoves.size(); i++) {
		if (!(boardRef.inBounds(possibleMoves[i])))
			possibleMoves.erase(possibleMoves.begin() + i);
	}

	return possibleMoves;
}