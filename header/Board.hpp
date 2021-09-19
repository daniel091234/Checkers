#pragma once

#include "IBoard.hpp"

class Board : public IBoard
{
public:
    Board() = default;
    ~Board() = default;
    void Draw();
};