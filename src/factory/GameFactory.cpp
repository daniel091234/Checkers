#include <vector>
#include <string>

#include "GameFactory.hpp"
#include "Player.hpp"

Game GameFactory::GetGame()
{
    return Game(GetPlayers());
}

std::vector<std::shared_ptr<IPlayer>> GameFactory::GetPlayers()
{
    constexpr auto NUM_OF_PLAYERS = 2u;
    std::vector<std::shared_ptr<IPlayer>> players;

    for (auto x = 0u; x < NUM_OF_PLAYERS; x++)
    {
        const auto& name = "Player " + std::to_string(x + 1);
        players.push_back(std::make_shared<Player>(name));
    }
    return players;
}

