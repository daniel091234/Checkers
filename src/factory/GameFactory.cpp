#include <vector>
#include <string>

#include "GameFactory.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Piece.hpp"

namespace 
{
    constexpr size_t BOARD_SIZE = 8u;
    constexpr size_t NUM_OF_PLAYERS = 2u;
}

Game GameFactory::GetGame()
{
    return Game(GetPlayers(), GetBoard(), GetPieces());
}

std::vector<std::shared_ptr<IPlayer>> GameFactory::GetPlayers()
{
    std::vector<std::shared_ptr<IPlayer>> players;

    for (auto x = 0u; x < NUM_OF_PLAYERS; x++)
    {
        const auto& name = "Player " + std::to_string(x + 1);
        players.push_back(std::make_shared<Player>(name));
    }
    return players;
}

std::shared_ptr<IBoard> GameFactory::GetBoard()
{
    return std::make_shared<Board>(BOARD_SIZE);
}

std::vector<std::shared_ptr<IPiece>> GameFactory::GetPieces()
{
    std::vector<std::shared_ptr<IPiece>> pieces;
    pieces.push_back(std::make_shared<Piece>());

    return pieces;
}
