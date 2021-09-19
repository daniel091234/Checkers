#include <iostream>
#include <array>

#include "GameFactory.hpp"

int main(int, char**) {

    std::cout << "Hello, world!\n";

    GameFactory gameFactory;
    auto game = gameFactory.GetGame();
    game.StartGame();
}
