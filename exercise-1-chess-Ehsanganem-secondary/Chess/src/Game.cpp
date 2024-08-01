#include "Game.h"
#include <iostream>

Game::Game(const std::string& initialBoard)
        : game(initialBoard), gameBoard(initialBoard), codeResponse(0) {}

void Game::run() {
    std::string res = game.getInput();
    while (res != "exit") {
        processMove(res);
        game.setCodeResponse(codeResponse);
        res = game.getInput();
    }
    std::cout << std::endl << "Exiting " << std::endl;
}

void Game::processMove(const std::string& res) {
    if (!isValidInput(res)) {
        codeResponse = 21; // Invalid move
        return;
    }

    int srcRow = gameBoard.calculateRow(res[0]);
    int srcCol = gameBoard.calculateCol(res[1]);
    int destRow = gameBoard.calculateRow(res[2]);
    int destCol = gameBoard.calculateCol(res[3]);

    std::shared_ptr<Piece> piece = gameBoard.getPiece(srcRow, srcCol);
    if (!piece) {
        codeResponse = 11;
    } else if (piece->getColor() != gameBoard.isWhiteTurn()) {
        codeResponse = 12;
    } else if (gameBoard.getPiece(destRow, destCol) && gameBoard.getPiece(destRow, destCol)->getColor() == piece->getColor()) {
        codeResponse = 13;
    } else if (!piece->can_move(srcRow, srcCol, destRow, destCol, gameBoard)) {
        codeResponse = 21;
    } else {
        std::shared_ptr<Piece> capturedPiece = gameBoard.getPiece(destRow, destCol);
        gameBoard.movePiece(srcRow, srcCol, destRow, destCol);
        if (gameBoard.isCheck(gameBoard.isWhiteTurn())) {
            codeResponse = 31;
            gameBoard.movePiece(destRow, destCol, srcRow, srcCol); // Undo move
            if (capturedPiece) {
                gameBoard.accessBoard(destRow, destCol) = capturedPiece; // Restore captured piece
            }
        } else {
            gameBoard.toggleTurn();
            if (gameBoard.isCheck(gameBoard.isWhiteTurn())) {
                codeResponse = 41;
            } else {
                codeResponse = 42;
            }
        }
    }
}

bool Game::isValidInput(const std::string& input) const {
    return input.size() == 4 &&
           ('a' <= input[0] && input[0] <= 'h') &&
           ('1' <= input[1] && input[1] <= '8') &&
           ('a' <= input[2] && input[2] <= 'h') &&
           ('1' <= input[3] && input[3] <= '8');
}
