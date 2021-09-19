#include <iostream>

#include "Game.hpp"

Game::Game(const std::vector<IPlayer>& players) : m_Players(players)
{
}


void Game::StartGame()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Game::EndGame()
{

}
