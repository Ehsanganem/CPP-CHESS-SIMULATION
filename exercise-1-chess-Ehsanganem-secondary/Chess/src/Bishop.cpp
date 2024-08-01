//
// Created by ganim on 05/06/2024.
//

#include "Bishop.h"
//can move diagonally
bool Bishop::can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) {
    if (abs(from_row - to_row) == abs(from_col - to_col)) {
        if (isPathClear(from_row, from_col, to_row, to_col, board)) {
            std::shared_ptr<Piece> target = board.getPiece(to_row, to_col);
            return !target || target->getColor() != getColor();
        }
    }
    std::cout << "invalid move for Bishop" << std::endl;
    return false;
}

//check for blocking by other pieces
bool Bishop::isPathClear(int fromRow, int fromCol, int toRow, int toCol, const Board &board) const {
    int rowStep = (toRow - fromRow) / std::abs(toRow - fromRow);
    int colStep = (toCol - fromCol) / std::abs(toCol - fromCol);

    for (int i = fromRow + rowStep, j = fromCol + colStep; i != toRow || j != toCol; i += rowStep, j += colStep) {
        if (board.getPiece(i, j)) {
            return false;
        }
    }
    return true;
}
