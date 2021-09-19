#pragma once

#include <vector>

#include "IGame.hpp"
#include "IPlayer.hpp"

class Game : public IGame
{
public:
    Game(const std::vector<IPlayer>&);
    ~Game() = default;
    void StartGame();
    void EndGame();

private:
    std::vector<IPlayer> m_Players;
};