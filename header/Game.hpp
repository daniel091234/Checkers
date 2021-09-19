#pragma once

#include <vector>
#include <memory>

#include "IGame.hpp"
#include "IPlayer.hpp"
#include "IBoard.hpp"
#include "IPiece.hpp"

class Game : public IGame
{
public:
    Game(const std::vector<std::shared_ptr<IPlayer>>&,
         const std::shared_ptr<IBoard>&,
         const std::vector<std::shared_ptr<IPiece>>&);
    ~Game() = default;
    void StartGame();
    void EndGame();

private:
    std::vector<std::shared_ptr<IPlayer>> m_Players;
    std::shared_ptr<IBoard> m_Board;
    std::vector<std::shared_ptr<IPiece>> m_Pieces;
};