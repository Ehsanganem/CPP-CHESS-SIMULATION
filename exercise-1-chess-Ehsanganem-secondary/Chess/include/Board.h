#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>
#include <map>
#include "Piece.h"
class Piece;
class Board {
public:
    Board(const std::string& boardString);
    std::shared_ptr<Piece> getPiece(int row, int col) const;
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
    void removePiece(int row, int col);
    bool isCheck(bool whiteTurn) const;

    int calculateRow(char row) const;
    int calculateCol(char col) const;
    bool isWhiteTurn() const;
    void toggleTurn();
    std::shared_ptr<Piece> &accessBoard(int row, int col);


private:
    std::map<char, int> rowMap;
    std::map<char, int> colMap;
    std::vector<std::shared_ptr<Piece>> board;
    bool whiteTurn = true; // true for white's turn, false for black's turn


};

#endif // BOARD_H
