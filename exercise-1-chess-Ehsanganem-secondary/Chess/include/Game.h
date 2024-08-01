//
// Created by ganim on 04/07/2024.
//

#ifndef EXERCISE_1_CHESSCPP_GAME_H
#define EXERCISE_1_CHESSCPP_GAME_H


#include "Chess.h"
#include "Board.h"
#include <string>
#include <memory>

class Game {
public:
    Game(const std::string& initialBoard);
    void run();

private:
    void processMove(const std::string& res);
    void handleInput();
    bool isValidInput(const std::string& input) const;

    Chess game;
    Board gameBoard;
    int codeResponse;
};

#endif //EXERCISE_1_CHESSCPP_GAME_H
