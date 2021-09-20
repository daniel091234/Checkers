#pragma once

#include <cstdlib>
#include <vector>
#include <memory>

#include "IBoard.hpp"
#include "ICell.hpp"

class Board : public IBoard
{
public:
    Board(const size_t& size);
    ~Board() = default;
    void Draw();
private:
    const void DrawBoardTopCorners() const;
    const void DrawBoardBottomCorners() const;
    const void DrawBoardMiddleCorners(const uint8_t&) const;
    const void DrawBoardCorners(const std::string&, const std::string&, const std::string&) const;
    const void DrawBoardCells() const;
    const void DrawBoardLetterLabel() const;

    const size_t m_Size;
    std::vector<std::vector<std::shared_ptr<ICell>>> m_Cells; // row and columun of cells
};