//
// Created by ganim on 05/06/2024.
//

#include "Knight.h"
//knight can move in L shape and can jump over pieces so no need for checking if path is clear
bool Knight::can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) {
    int row_diff = abs(to_row - from_row);
    int col_diff = abs(to_col - from_col);
    if ((row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2)) {
        std::shared_ptr<Piece> target = board.getPiece(to_row, to_col);
        return !target || target->getColor() != getColor();
    }
    std::cout << "invalid move for knight" << std::endl;
    return false;
}



