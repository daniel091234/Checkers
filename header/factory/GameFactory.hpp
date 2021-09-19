#pragma once

#include <memory>

#include "Game.hpp"

class GameFactory
{
public:
    GameFactory() = default;
    ~GameFactory() = default;

    Game GetGame();
    std::vector<std::shared_ptr<IPlayer>> GetPlayers();
};
