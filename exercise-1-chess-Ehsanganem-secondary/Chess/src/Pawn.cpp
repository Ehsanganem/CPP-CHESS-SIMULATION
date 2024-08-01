#include "Pawn.h"

bool Pawn::can_move(int from_row, int from_col, int to_row, int to_col, const Board &board) {
    int direction = getColor() ? 1 : -1; // White pawns move up (positive), black pawns move down (negative)

    // basic move forward
    if (from_col == to_col) {
        if (to_row - from_row == direction) {
            return !board.getPiece(to_row, to_col); // Must move to an empty square
        }
        // double move
        if ((from_row == 1 && direction == 1 || from_row == 6 && direction == -1) && to_row - from_row == 2 * direction) {
            return isPathClear(from_row, from_col, to_row, to_col, board);
        }
    } else if (abs(to_col - from_col) == 1 && to_row - from_row == direction) {
        // capture move
        std::shared_ptr<Piece> targetPiece = board.getPiece(to_row, to_col);
        return targetPiece && targetPiece->getColor() != getColor();
    }
    return false;
}

bool Pawn::isPathClear(int from_row, int from_col, int to_row, int to_col, const Board &board) const {
    int direction = getColor() ? 1 : -1;
    int intermediate_row = from_row + direction;
    return !board.getPiece(intermediate_row, from_col) && !board.getPiece(to_row, to_col);
}
