#pragma once

#include <memory>

#include "IGameFactory.hpp"
#include "Game.hpp"
#include "IPlayer.hpp"

class GameFactory : IGameFactory
{
public:
    GameFactory() = default;
    ~GameFactory() = default;

    Game GetGame();

private:
    std::vector<std::shared_ptr<IPlayer>> GetPlayers();
    std::shared_ptr<IBoard> GetBoard();
    std::vector<std::shared_ptr<IPiece>> GetPieces();
};
