#include <iostream>

#include "Board.hpp"
#include "Cell.hpp"

Board::Board(const size_t& size) : m_Size(size)
{
    m_Cells.reserve(m_Size);
    for (int x = 0; x < m_Size; x++)
    {
        std::vector<std::shared_ptr<ICell>> row;
        row.reserve(m_Size);
        for (int y = 0; y < m_Size; y++)
        {
            const auto& cell = std::make_shared<Cell>();
            row.push_back(cell);
        }
        m_Cells.push_back(row);
    }
}

void Board::Draw()
{
    DrawBoardTopCorners();
    DrawBoardCells();
    DrawBoardBottomCorners();
}

const void Board::DrawBoardTopCorners() const
{
    DrawBoardLetterLabel();
    DrawBoardCorners(" ┌──", "─┬──", "─┐ ");
}

const void Board::DrawBoardCells() const
{
    int numberLabel = m_Size;

    for (const auto rows : m_Cells)
    {
        std::cout << numberLabel << "│";
        for (const auto cell : rows)
        {
            std::cout << " " << cell->GetValue() << " │";
        }
        std::cout << numberLabel-- << std::endl;
        DrawBoardMiddleCorners(numberLabel);
    }
}


const void Board::DrawBoardBottomCorners() const
{
    DrawBoardCorners(" └──", "─┴──", "─┘ ");
    DrawBoardLetterLabel();
}

const void Board::DrawBoardMiddleCorners(const uint8_t& numberLabel) const
{
    if (numberLabel <= 0)
    {
        return;
    }
    DrawBoardCorners(" ├──", "─┼──", "─┤ ");
}

const void Board::DrawBoardCorners(const std::string& leftPiece,
                                   const std::string& middlePiece,
                                   const std::string& rightPiece) const
{
    std::cout << leftPiece;
    for (int x = 0; x < m_Size - 1; x++)
    {
        std::cout << middlePiece;
    }
    std::cout << rightPiece <<std::endl;
}

const void Board::DrawBoardLetterLabel() const
{
    std::cout << "  ";
    for (int x = 0; x < m_Size; x++)
    {
        const char label = 'A' + x;
        std::cout << " " << label << "  ";
    }
    std::cout << " " <<std::endl;
}


