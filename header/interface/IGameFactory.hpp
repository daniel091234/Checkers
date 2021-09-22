#pragma once

#include "Game.hpp"

class IGameFactory
{
public:
    virtual Game GetGame() = 0;
};