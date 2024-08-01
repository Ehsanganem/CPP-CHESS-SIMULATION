//
// Created by ganim on 08/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_KING_H
#define EXERCISE_1_CHESSCPP_KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(bool isWhite, int row, int col) : Piece(Type::King,isWhite, row, col) {}
    bool can_move(int from_row, int from_col, int to_row, int to_col, const Board& board) override;
    bool isPathClear(int from_row, int from_col, int to_row, int to_col, const Board& board) const override;
};





#endif //EXERCISE_1_CHESSCPP_KING_H
