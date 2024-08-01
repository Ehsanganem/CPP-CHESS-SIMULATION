#include "Piece.h"
//piece is an abstract class used Factory method design pattern (learned in advanced cpp coursr)
Piece::Piece(Type type, bool white, int row, int col) : type(type), whiteTurn(white), row(row), col(col) {}

Type Piece::getType() const {
    return this->type;
}

int Piece::getRow() const {
    return this->row;
}

int Piece::getCol() const {
    return this->col;
}

void Piece::setCol(int col) {
    this->col = col;
}

void Piece::setRow(int row) {
    this->row = row;
}

Piece::~Piece() {}

bool Piece::getColor() const {
    return whiteTurn;
}
