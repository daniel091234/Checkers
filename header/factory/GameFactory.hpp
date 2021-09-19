#pragma once

#include "Game.hpp"

class GameFactory
{
public:
    GameFactory() = default;
    ~GameFactory() = default;

    Game GetGame();
    std::vector<IPlayer> GetPlayers();
};
