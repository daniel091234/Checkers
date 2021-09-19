#include <iostream>

#include "Game.hpp"
#include "Player.hpp"

Game::Game(const std::vector<std::shared_ptr<IPlayer>>& players,
           const std::shared_ptr<IBoard>& board,
           const std::vector<std::shared_ptr<IPiece>>& pieces)
    : m_Players(players),
      m_Board(board),
      m_Pieces(pieces)
{
    for (auto player : m_Players)
    {
        std::cout << player->GetName() << " has joined the Game" << std::endl;
    }
}


void Game::StartGame()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_Board->Draw();
}

void Game::EndGame()
{

}
