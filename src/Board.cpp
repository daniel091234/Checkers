#include <iostream>

#include "Board.hpp"
#include "Cell.hpp"
#include "BoardRowBuilder.hpp"

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
    m_BoardRowBuilder = std::make_shared<BoardRowBuilder>(m_Size);
}

void Board::Draw()
{
    std::cout << m_BoardRowBuilder->GetTopSide();
    DrawBoardCells();
    std::cout << m_BoardRowBuilder->GetBottomSide();
}

const void Board::DrawBoardCells() const
{
    int numberLabel = m_Size;

    for (const auto row : m_Cells)
    {
        const auto& values = GetRowValues(row);
        std::cout << m_BoardRowBuilder->GetMiddleSide(values, numberLabel);
        numberLabel--;        
    }
}

std::string Board::GetRowValues(const std::vector<std::shared_ptr<ICell>>& row) const
{
    std::string rowValues;
    for (const auto& cell : row)
    {
        rowValues.append(cell->GetValue());
    }
    return rowValues;
}