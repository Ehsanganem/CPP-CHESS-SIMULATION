//
// Created by ganim on 04/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_QUEEN_H
#define EXERCISE_1_CHESSCPP_QUEEN_H
#include "Piece.h"

class Queen: public Piece{
public:
    Queen(bool white, int row, int col): Piece(Type::Queen,white,row,col){}
    bool can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) override;
    ~Queen() override = default;
    bool isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const override;

};


#endif //EXERCISE_1_CHESSCPP_QUEEN_H
