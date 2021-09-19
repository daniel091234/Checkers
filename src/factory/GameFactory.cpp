#include <vector>

#include "GameFactory.hpp"
#include "Player.hpp"

Game GameFactory::GetGame()
{
    return Game(GetPlayers());
}

std::vector<IPlayer> GameFactory::GetPlayers()
{
    constexpr auto NUM_OF_PLAYERS = 2u;
    std::vector<IPlayer> players;

    for (auto x = 0u; x < NUM_OF_PLAYERS; x++)
    {
        players.push_back(Player());
    }
    return players;
}

