#include <iostream>

#include "Game.hpp"
#include "Player.hpp"

Game::Game(const std::vector<std::shared_ptr<IPlayer>>& players) : m_Players(players)
{
    for (auto player : m_Players)
    {
        std::cout << player->GetName() << " has joined the Game" << std::endl;
    }
}


void Game::StartGame()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Game::EndGame()
{

}
