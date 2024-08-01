#include "King.h"
#include "Board.h"

bool King::can_move(int from_row, int from_col, int to_row, int to_col, const Board& board) {
    int row_diff = abs(to_row - from_row);
    int col_diff = abs(to_col - from_col);

    // The King can move one square in any direction
    if ((row_diff <= 1) && (col_diff <= 1)) {
        std::shared_ptr<Piece> destPiece = board.getPiece(to_row, to_col);
        return !destPiece || (destPiece->getColor() != this->getColor());
    }
    return false;
}


bool King::isPathClear(int from_row, int from_col, int to_row, int to_col, const Board& board) const {
    // The King's path is always clear because it only moves one square
    return true;
}