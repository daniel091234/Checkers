#pragma once

#include <vector>
#include <memory>

#include "IGame.hpp"
#include "IPlayer.hpp"

class Game : public IGame
{
public:
    Game(const std::vector<std::shared_ptr<IPlayer>>&);
    ~Game() = default;
    void StartGame();
    void EndGame();

private:
    std::vector<std::shared_ptr<IPlayer>> m_Players;
};