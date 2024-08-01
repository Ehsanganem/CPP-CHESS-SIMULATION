//
// Created by ganim on 04/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_PAWN_H
#define EXERCISE_1_CHESSCPP_PAWN_H
#include "Piece.h"

class Pawn: public Piece{
public:
    Pawn(bool white,int col,int row): Piece(Type::Pawn,white,row,col){}
    bool can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) override;
    ~Pawn() override = default;
    bool isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const override;
};


#endif //EXERCISE_1_CHESSCPP_PAWN_H
