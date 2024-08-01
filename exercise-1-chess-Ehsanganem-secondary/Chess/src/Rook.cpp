#include "Rook.h"
//rook can move in straight lines
bool Rook::can_move(int fromRow, int fromCol, int toRow, int toCol, const Board &board) {
    if (fromCol != toCol && fromRow != toRow) {
        std::cout << "invalid move" << std::endl; // can either move horizontally or vertically
        return false;
    }
    if (isPathClear(fromRow, fromCol, toRow, toCol, board)) {
        std::shared_ptr<Piece> target = board.getPiece(toRow, toCol);
        return !target || target->getColor() != getColor();
    }
    return false;
}

//check if rook isnt blocked
bool Rook::isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const {
    int rowStep = (to_row - from_row) == 0 ? 0 : (to_row - from_row) / std::abs(to_row - from_row);
    int colStep = (to_col - from_col) == 0 ? 0 : (to_col - from_col) / std::abs(to_col - from_col);

    for (int i = from_row + rowStep, j = from_col + colStep; i != to_row || j != to_col; i += rowStep, j += colStep) {
        if (board.getPiece(i, j)) {
            return false;
        }
    }
    return true;
}
