#pragma once

#include "IPiece.hpp"

class Piece : public IPiece
{
public:
    Piece() = default;
    ~Piece() = default;
    void Move();
};
