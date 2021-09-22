#pragma once

#include <cstdlib>
#include <vector>
#include <memory>

#include "IBoard.hpp"
#include "ICell.hpp"
#include "IBoardRowBuilder.hpp"

class Board : public IBoard
{
public:
    Board(const size_t& size);
    ~Board() = default;
    void Draw();
private:
    const void DrawBoardMiddleCorners(const uint8_t&) const;
    const void DrawBoardCells() const;

    const size_t m_Size;
    std::vector<std::vector<std::shared_ptr<ICell>>> m_Cells; // row and columun of cells
    std::shared_ptr<IBoardRowBuilder> m_BoardRowBuilder;
};