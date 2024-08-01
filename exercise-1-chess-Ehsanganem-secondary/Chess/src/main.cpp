#include "Game.h"
#include <iostream>
#include <string>

int main() {
    std::string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
    Game game(board);
    game.run();
    return 0;
}
