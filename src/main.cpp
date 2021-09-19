#include <iostream>
#include <array>

#include "GameFactory.hpp"

int main(int, char**) 
{
    GameFactory gameFactory;
    auto game = gameFactory.GetGame();
    game.StartGame();
}
