//
// Created by ganim on 05/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_BISHOP_H
#define EXERCISE_1_CHESSCPP_BISHOP_H
#include "Piece.h"

class Bishop: public Piece{
public:
    Bishop(bool white,int row,int col): Piece(Type::Bishop,white,row,col){}
    bool can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) override;
    ~Bishop() override = default;
    bool isPathClear(int fromRow, int fromCol, int toRow, int toCol,const Board &board) const override;

};


#endif //EXERCISE_1_CHESSCPP_BISHOP_H
