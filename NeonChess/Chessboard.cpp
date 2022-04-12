#include "Chessboard.h"


ChessBoard::ChessBoard() {
	//white team
	ChessPiece* whiteRook1 = new ChessPiece(Colour::WHITE, PieceType::ROOK, glm::vec2(0, 0)); //a1
	ChessPiece* whiteKnight1 = new ChessPiece(Colour::WHITE, PieceType::KNIGHT, glm::vec2(1, 0)); //b1
	ChessPiece* whiteBishop1 = new ChessPiece(Colour::WHITE, PieceType::BISHOP, glm::vec2(2, 0)); //c1
	ChessPiece* whiteKing = new ChessPiece(Colour::WHITE, PieceType::KING, glm::vec2(3, 0)); //d1
	ChessPiece* whiteQueen = new ChessPiece(Colour::WHITE, PieceType::QUEEN, glm::vec2(4, 0)); //e1
	ChessPiece* whiteBishop2 = new ChessPiece(Colour::WHITE, PieceType::BISHOP, glm::vec2(5, 0)); //f1
	ChessPiece* whiteKnight2 = new ChessPiece(Colour::WHITE, PieceType::KNIGHT, glm::vec2(6, 0)); //g1
	ChessPiece* whiteRook2 = new ChessPiece(Colour::WHITE, PieceType::ROOK, glm::vec2(7, 0)); //h1
	//black team
	ChessPiece* blackRook1 = new ChessPiece(Colour::BLACK, PieceType::ROOK, glm::vec2(0, 7)); //a8
	ChessPiece* blackKnight1 = new ChessPiece(Colour::BLACK, PieceType::KNIGHT, glm::vec2(1, 7)); //b8
	ChessPiece* blackBishop1 = new ChessPiece(Colour::BLACK, PieceType::BISHOP, glm::vec2(2, 7)); //c8
	ChessPiece* blackKing = new ChessPiece(Colour::BLACK, PieceType::KING, glm::vec2(3, 7)); //d8
	ChessPiece* blackQueen = new ChessPiece(Colour::BLACK, PieceType::QUEEN, glm::vec2(4, 7)); //e8
	ChessPiece* blackBishop2 = new ChessPiece(Colour::BLACK, PieceType::BISHOP, glm::vec2(5, 7)); //f8
	ChessPiece* blackKnight2 = new ChessPiece(Colour::BLACK, PieceType::KNIGHT, glm::vec2(6, 7)); //g8
	ChessPiece* blackRook2 = new ChessPiece(Colour::BLACK, PieceType::ROOK, glm::vec2(7, 7)); //h8

}

void ChessBoard::setPiece(const glm::ivec2& location, ChessPiece* refPiece) {
	chessboard[location.x + (location.y * 8)] = refPiece;
}

ChessPiece*& ChessBoard::getPiece(const glm::ivec2& location)
{
	return chessboard[location.x + (location.y * 8)];
}

