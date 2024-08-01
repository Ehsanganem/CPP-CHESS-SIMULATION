//
// Created by ganim on 05/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_KNIGHT_H
#define EXERCISE_1_CHESSCPP_KNIGHT_H
#include "Piece.h"

class Knight: public Piece{
public:
    Knight(bool white,int row,int col): Piece(Type::Knight,white,row,col){}
    bool can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) override;
    ~Knight() override = default;
    bool isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const override {
        return true; // Knights can jump so the path is always clear
    }


};


#endif //EXERCISE_1_CHESSCPP_KNIGHT_H
