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
	//black team
	setPiece(glm::ivec2(0, 7), new ChessPiece(Colour::BLACK, PieceType::ROOK)); //a8
	setPiece(glm::ivec2(1, 7), new ChessPiece(Colour::BLACK, PieceType::KNIGHT)); //b8
	setPiece(glm::ivec2(2, 7), new ChessPiece(Colour::BLACK, PieceType::BISHOP)); //c8
	setPiece(glm::ivec2(3, 7), new ChessPiece(Colour::BLACK, PieceType::KING)); //d8
	setPiece(glm::ivec2(4, 7), new ChessPiece(Colour::BLACK, PieceType::QUEEN)); //e8
	setPiece(glm::ivec2(5, 7), new ChessPiece(Colour::BLACK, PieceType::BISHOP)); //f8
	setPiece(glm::ivec2(6, 7), new ChessPiece(Colour::BLACK, PieceType::KNIGHT)); //g8
	setPiece(glm::ivec2(7, 7), new ChessPiece(Colour::BLACK, PieceType::ROOK)); //h8

}

void ChessBoard::setPiece(const glm::ivec2& location, ChessPiece* refPiece) {
	chessboard[location.x + (location.y * 8)] = refPiece;
}

ChessPiece*& ChessBoard::getPiece(const glm::ivec2& location)
{
	return chessboard[location.x + (location.y * 8)];
}

