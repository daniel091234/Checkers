#pragma once

#include <string>

#include "IPlayer.hpp"

class Player : public IPlayer
{
public:
    Player(const std::string&);
    ~Player() = default;
    std::string GetName();

private:
    const std::string m_Name;
};