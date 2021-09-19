#pragma once

#include <cstdlib>

#include "IBoard.hpp"

class Board : public IBoard
{
public:
    Board(const size_t& size);
    ~Board() = default;
    void Draw();
    const size_t& GetSize() const;
private:
    size_t m_Size;
};