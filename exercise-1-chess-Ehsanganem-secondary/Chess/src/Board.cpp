#include "Board.h"
#include "Rook.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include <iostream>
#include <cmath>
const bool WHITE_PIECE = true;
const bool BLACK_PIECE = false;
//board installization and map for coordinates
Board::Board(const std::string& boardString) : board(64), whiteTurn(true) {
    for (size_t i = 0; i < boardString.size(); ++i) {
        char pieceChar = boardString[i];
        switch (pieceChar) {
            case 'R': board[i] = std::make_shared<Rook>(WHITE_PIECE, i / 8, i % 8); break;
            case 'r': board[i] = std::make_shared<Rook>(BLACK_PIECE, i / 8, i % 8); break;
            case 'P': board[i] = std::make_shared<Pawn>(WHITE_PIECE, i / 8, i % 8); break;
            case 'p': board[i] = std::make_shared<Pawn>(BLACK_PIECE, i / 8, i % 8); break;
            case 'Q': board[i] = std::make_shared<Queen>(WHITE_PIECE, i / 8, i % 8); break;
            case 'q': board[i] = std::make_shared<Queen>(BLACK_PIECE, i / 8, i % 8); break;
            case 'B': board[i] = std::make_shared<Bishop>(WHITE_PIECE, i / 8, i % 8); break;
            case 'b': board[i] = std::make_shared<Bishop>(BLACK_PIECE, i / 8, i % 8); break;
            case 'N': board[i] = std::make_shared<Knight>(WHITE_PIECE, i / 8, i % 8); break;
            case 'n': board[i] = std::make_shared<Knight>(BLACK_PIECE, i / 8, i % 8); break;
            case 'K': board[i] = std::make_shared<King>(WHITE_PIECE, i / 8, i % 8); break;
            case 'k': board[i] = std::make_shared<King>(BLACK_PIECE, i / 8, i % 8); break;
            default: board[i] = nullptr; break;
        }
    }
    rowMap = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}};
    colMap = {{'1', 0}, {'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}};
}

std::shared_ptr<Piece> Board::getPiece(int row, int col) const {
    if (row < 0 || row >= 8 || col < 0 || col >= 8) return nullptr;
    return board[row * 8 + col];
}

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    std::shared_ptr<Piece> capturedPiece = board[toRow * 8 + toCol];
    if (capturedPiece) {
        if (capturedPiece->getColor() != board[fromRow * 8 + fromCol]->getColor()) {
            removePiece(toRow, toCol);
        } else {
            std::cout << "Cannot capture your own piece at " << toRow << "," << toCol << std::endl;
            return; // cannot move to a square occupied by own piece
        }
    }
    board[toRow * 8 + toCol] = std::move(board[fromRow * 8 + fromCol]);
    board[toRow * 8 + toCol]->setRow(toRow);
    board[toRow * 8 + toCol]->setCol(toCol);
}

void Board::removePiece(int row, int col) {
    board[row * 8 + col] = nullptr;
}

bool Board::isCheck(bool whiteTurn) const {
    int kingRow, kingCol;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            std::shared_ptr<Piece> piece = getPiece(row, col);
            if (piece && piece->getType() == Type::King && piece->getColor() == whiteTurn) {
                kingRow = row;
                kingCol = col;
            }
        }
    }

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            std::shared_ptr<Piece> piece = getPiece(row, col);
            if (piece && piece->getColor() != whiteTurn && piece->can_move(row, col, kingRow, kingCol, *this)) {
                return true;
            }
        }
    }

    return false;
}

bool Board::isWhiteTurn() const {
    return whiteTurn;
}

void Board::toggleTurn() {
    whiteTurn = !whiteTurn;
}

int Board::calculateRow(char row) const {
    return rowMap.at(row);
}

int Board::calculateCol(char col) const {
    return colMap.at(col);
}
//help function for accessing the board
std::shared_ptr<Piece>& Board::accessBoard(int row, int col) {
    return board[row * 8 + col];
}
