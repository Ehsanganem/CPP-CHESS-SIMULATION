//
// Created by ganim on 04/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_PIECE_H
#define EXERCISE_1_CHESSCPP_PIECE_H
#include "Board.h"
#include "ChessException.h"
#include <iostream>
class Board;

enum class Type {
    Rook,
    Knight,
    Bishop,
    Queen,
    Pawn,
    King
};

class Piece {
protected:
    Type type;
    bool whiteTurn;
    int row;
    int col;

public:
    Piece(Type type, bool white, int row, int col);
    virtual bool can_move(int from_row, int from_col, int to_row, int to_col, const Board& board) = 0;
    virtual bool isPathClear(int from_row, int from_col, int to_row, int to_col, const Board& board) const = 0;
    Type getType() const;
    int getRow() const;
    int getCol() const;
    void setRow(int row);
    void setCol(int col);
    bool getColor() const;
    virtual ~Piece();
};


#endif //EXERCISE_1_CHESSCPP_PIECE_H
