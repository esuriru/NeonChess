#pragma once
#include "Chessboard.h"

class ChessGame {
private:
	ChessBoard gameboard;
public:
	ChessGame();
	ChessBoard getBoard() const;

};