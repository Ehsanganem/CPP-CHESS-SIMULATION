//
// Created by ganim on 04/06/2024.
//

#ifndef EXERCISE_1_CHESSCPP_ROOK_H
#define EXERCISE_1_CHESSCPP_ROOK_H

#include "Piece.h"
#include "Board.h"

class Rook : public Piece {
public:
    Rook(bool white, int row, int col) : Piece(Type::Rook, white, row, col) {}
    bool can_move(int fromRow, int fromCol, int toRow, int toCol, const Board &board) override;
    bool isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const override;
    ~Rook() override = default;
};

#endif //EXERCISE_1_CHESSCPP_ROOK_H

