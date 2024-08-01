#include "Queen.h"

bool Queen::can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) {
    if (from_row == to_row || from_col == to_col || abs(from_row - to_row) == abs(from_col - to_col)) {
        if (isPathClear(from_row, from_col, to_row, to_col, board)) {
            std::shared_ptr<Piece> target = board.getPiece(to_row, to_col);
            return !target || target->getColor() != getColor();
        }
    }
    std::cout << "invalid move for queen" << std::endl;
    return false;
}


bool Queen::isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const {
    int rowStep = (to_row - from_row) == 0 ? 0 : (to_row - from_row) / std::abs(to_row - from_row);
    int colStep = (to_col - from_col) == 0 ? 0 : (to_col - from_col) / std::abs(to_col - from_col);

    for (int i = from_row + rowStep, j = from_col + colStep; i != to_row || j != to_col; i += rowStep, j += colStep) {
        if (board.getPiece(i, j)) {
            return false;
        }
    }
    return true;
}
