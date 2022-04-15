#include "Chessboard.h"
#include <iostream>

ChessBoard::ChessBoard() {
	//white team
	chessboard.fill(nullptr);
	setPiece(glm::ivec2(0, 0), new ChessPiece(Colour::WHITE, PieceType::ROOK)); //a1
	setPiece(glm::ivec2(1, 0), new ChessPiece(Colour::WHITE, PieceType::KNIGHT)); //b1
	setPiece(glm::ivec2(2, 0), new ChessPiece(Colour::WHITE, PieceType::BISHOP)); //c1
	setPiece(glm::ivec2(3, 0), new ChessPiece(Colour::WHITE, PieceType::KING)); //d1
	setPiece(glm::ivec2(4, 0), new ChessPiece(Colour::WHITE, PieceType::QUEEN)); //e1
	setPiece(glm::ivec2(5, 0), new ChessPiece(Colour::WHITE, PieceType::BISHOP)); //f1
	setPiece(glm::ivec2(6, 0), new ChessPiece(Colour::WHITE, PieceType::KNIGHT)); //g1
	setPiece(glm::ivec2(7, 0), new ChessPiece(Colour::WHITE, PieceType::ROOK)); //h1
	for (int i = 0; i < 8; ++i) {
		setPiece(glm::ivec2(i, 1), new ChessPiece(Colour::WHITE, PieceType::PAWN));
	}
	//black team
	setPiece(glm::ivec2(0, 7), new ChessPiece(Colour::BLACK, PieceType::ROOK)); //a8
	setPiece(glm::ivec2(1, 7), new ChessPiece(Colour::BLACK, PieceType::KNIGHT)); //b8
	setPiece(glm::ivec2(2, 7), new ChessPiece(Colour::BLACK, PieceType::BISHOP)); //c8
	setPiece(glm::ivec2(3, 7), new ChessPiece(Colour::BLACK, PieceType::KING)); //d8
	setPiece(glm::ivec2(4, 7), new ChessPiece(Colour::BLACK, PieceType::QUEEN)); //e8
	setPiece(glm::ivec2(5, 7), new ChessPiece(Colour::BLACK, PieceType::BISHOP)); //f8
	setPiece(glm::ivec2(6, 7), new ChessPiece(Colour::BLACK, PieceType::KNIGHT)); //g8
	setPiece(glm::ivec2(7, 7), new ChessPiece(Colour::BLACK, PieceType::ROOK)); //h8
	for (int i = 0; i < 8; ++i) {
		setPiece(glm::ivec2(i, 6), new ChessPiece(Colour::BLACK, PieceType::PAWN));
	}
}

void ChessBoard::setPiece(const glm::ivec2& location, ChessPiece* refPiece) {
	chessboard[location.x + (location.y * 8)] = refPiece;
}

ChessPiece*& ChessBoard::getPiece(const glm::ivec2& location)
{
	return chessboard[location.x + (location.y * 8)];
}

const std::vector<glm::ivec2>& ChessBoard::getPossibleMoves(ChessPiece* refPiece) 
{
	if (refPiece == nullptr) throw std::invalid_argument("Not a piece");
	glm::ivec2 currentLocation = getPieceLocation(refPiece);
	std::vector<glm::ivec2> possibleMoves;
	switch (refPiece->getPieceType()) {
	case PieceType::KING: {
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
			if (!(inBounds(possibleMoves[i])))
				possibleMoves.erase(possibleMoves.begin() + i);
		}

		return possibleMoves;
	}
	case PieceType::PAWN: {
		if (refPiece->getPieceColour() == Colour::WHITE) {
			if (getPiece(currentLocation + glm::ivec2(0, 1)) == nullptr)
				possibleMoves.push_back(currentLocation + glm::ivec2(0, 1));
			if (currentLocation.y == 1)
				//first move
				possibleMoves.push_back(currentLocation + glm::ivec2(0, 2));
			if (getPiece(currentLocation + glm::ivec2(1, 1)) != nullptr && getPiece(currentLocation + glm::ivec2(1, 1))->getPieceColour() == Colour::BLACK)
				possibleMoves.push_back(currentLocation + glm::ivec2(1, 1));
			if (getPiece(currentLocation + glm::ivec2(-1, 1)) != nullptr && getPiece(currentLocation + glm::ivec2(-1, 1))->getPieceColour() == Colour::BLACK)
				possibleMoves.push_back(currentLocation + glm::ivec2(-1, 1));
			return possibleMoves;
		}
		else {
			if (getPiece(currentLocation + glm::ivec2(0, -1)) == nullptr)
				possibleMoves.push_back(currentLocation + glm::ivec2(0, -1));
			if (currentLocation.y == 6)
				//first move
				possibleMoves.push_back(currentLocation + glm::ivec2(0, -2));
			if (getPiece(currentLocation + glm::ivec2(1, -1)) != nullptr && getPiece(currentLocation + glm::ivec2(1, -1))->getPieceColour() == Colour::BLACK)
				possibleMoves.push_back(currentLocation + glm::ivec2(1, -1));
			if (getPiece(currentLocation + glm::ivec2(-1, -1)) != nullptr && getPiece(currentLocation + glm::ivec2(-1, -1))->getPieceColour() == Colour::BLACK)
				possibleMoves.push_back(currentLocation + glm::ivec2(-1, -1));
			return possibleMoves;
		}
	}
	case PieceType::QUEEN: {
		//Bishop
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(i, i))) {
				if (getPiece(currentLocation + glm::ivec2(i, i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(i, i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(i, -i))) {
				if (getPiece(currentLocation + glm::ivec2(i, -i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, -i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(i, -i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(-i, i))) {
				if (getPiece(currentLocation + glm::ivec2(-i, i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(-i, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(-i, i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(-i, -i))) {
				if (getPiece(currentLocation + glm::ivec2(-i, -i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(-i, -i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(-i, -i));
				}
				else break;
			}
		}
		//Rook
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(0, i))) {
				if (getPiece(currentLocation + glm::ivec2(0, i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(0, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(0, i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(0, -i))) {
				if (getPiece(currentLocation + glm::ivec2(0, -i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(0, -i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(0, -i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(i, 0))) {
				if (getPiece(currentLocation + glm::ivec2(i, 0))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, 0)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(i, 0));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(-i, 0))) {
				if (getPiece(currentLocation + glm::ivec2(-i, 0))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(-i, 0)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(-i, 0));
				}
				else break;
			}
		}
	}
	case PieceType::BISHOP: {
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(i, i))) {
				if (getPiece(currentLocation + glm::ivec2(i, i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(i, i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(i, -i))) {
				if (getPiece(currentLocation + glm::ivec2(i, -i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(i, -i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(-i, i))) {
				if (getPiece(currentLocation + glm::ivec2(-i, i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(-i, i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (inBounds(currentLocation + glm::ivec2(-i, -i))) {
				if (getPiece(currentLocation + glm::ivec2(-i, -i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(-i, -i));
				}
				else break;
			}
		}
	}
	case PieceType::ROOK: {
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(0, i))) {
				if (getPiece(currentLocation + glm::ivec2(0, i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(0, i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(0, i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(0, -i))) {
				if (getPiece(currentLocation + glm::ivec2(0, -i))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(0, -i)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(0, -i));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(i, 0))) {
				if (getPiece(currentLocation + glm::ivec2(i, 0))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(i, 0)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(i, 0));
				}
				else break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (inBounds(currentLocation + glm::ivec2(-i, 0))) {
				if (getPiece(currentLocation + glm::ivec2(-i, 0))->getPieceColour() != refPiece->getPieceColour() || getPiece(currentLocation + glm::ivec2(-i, 0)) == nullptr) {
					possibleMoves.push_back(currentLocation + glm::ivec2(-i, 0));
				}
				else break;
			}
		}
	}
	case PieceType::KNIGHT: {
		possibleMoves.push_back(currentLocation + glm::ivec2(1, 2));
		possibleMoves.push_back(currentLocation + glm::ivec2(-1, 2));
		possibleMoves.push_back(currentLocation + glm::ivec2(1, -2));
		possibleMoves.push_back(currentLocation + glm::ivec2(-1, -2));
		possibleMoves.push_back(currentLocation + glm::ivec2(2, 1));
		possibleMoves.push_back(currentLocation + glm::ivec2(-2, 1));
		possibleMoves.push_back(currentLocation + glm::ivec2(2, -1));
		possibleMoves.push_back(currentLocation + glm::ivec2(-2, -1));

		for (int i = 0; i < possibleMoves.size(); i++) {
			if (!(inBounds(possibleMoves[i])))
				possibleMoves.erase(possibleMoves.begin() + i);
		}

		return possibleMoves;
	}
	}

}

const glm::ivec2& ChessBoard::getPieceLocation(ChessPiece* refPiece) const
{
	for (int i = 0; i < chessboard.size(); i++) {
		if (refPiece == chessboard[i]) {
			return glm::ivec2(i % 8, (i - (i % 8)) / 8);
		}
	}
}

bool ChessBoard::inBounds(const glm::ivec2& location)
{
	return !(location.x > 7 || location.y > 7 || location.x < 0 || location.y < 0);
}

