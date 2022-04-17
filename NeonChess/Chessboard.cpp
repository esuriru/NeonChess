#include "Chessboard.h"
#include "rook.h"
#include "bishop.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include <iostream>

ChessBoard::ChessBoard() {
	//white team	
	chessboard.fill(nullptr);
	setPiece(glm::ivec2(0, 0), new Rook(Colour::WHITE, *this)); //a1
	setPiece(glm::ivec2(1, 0), new Knight(Colour::WHITE, *this)); //b1
	setPiece(glm::ivec2(2, 0), new Bishop(Colour::WHITE, *this)); //c1
	setPiece(glm::ivec2(3, 0), new King(Colour::WHITE, *this)); //d1
	setPiece(glm::ivec2(4, 0), new Queen(Colour::WHITE, *this)); //e1
	setPiece(glm::ivec2(5, 0), new Bishop(Colour::WHITE, *this)); //f1
	setPiece(glm::ivec2(6, 0), new Knight(Colour::WHITE, *this)); //g1
	setPiece(glm::ivec2(7, 0), new Rook(Colour::WHITE, *this)); //h1
	for (int i = 0; i < 8; ++i) {
		setPiece(glm::ivec2(i, 1), new Pawn(Colour::WHITE, *this));
	}
	//black team
	setPiece(glm::ivec2(0, 7), new Rook(Colour::BLACK, *this)); //a8
	setPiece(glm::ivec2(1, 7), new Knight(Colour::BLACK, *this)); //b8
	setPiece(glm::ivec2(2, 7), new Bishop(Colour::BLACK, *this)); //c8
	setPiece(glm::ivec2(3, 7), new King(Colour::BLACK, *this)); //d8
	setPiece(glm::ivec2(4, 7), new Queen(Colour::BLACK, *this)); //e8
	setPiece(glm::ivec2(5, 7), new Bishop(Colour::BLACK, *this)); //f8
	setPiece(glm::ivec2(6, 7), new Knight(Colour::BLACK, *this)); //g8
	setPiece(glm::ivec2(7, 7), new Rook(Colour::BLACK, *this)); //h8
	for (int i = 0; i < 8; ++i) {
		setPiece(glm::ivec2(i, 6), new Pawn(Colour::BLACK, *this));
	}
}

void ChessBoard::setPiece(const glm::ivec2& location, ChessPiece* refPiece) {
	chessboard[location.x + (location.y * 8)] = refPiece;
}

ChessPiece*& ChessBoard::getPiece(const glm::ivec2& location)
{
	return chessboard[location.x + (location.y * 8)];
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

