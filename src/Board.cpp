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
    std::cout << "   A   B   C   D   E   F   G   H   " <<std::endl;
    std::cout << " ┌───┬───┬───┬───┬───┬───┬───┬───┐ " <<std::endl;

    int numberLabel = m_Size;

    for (const auto rows : m_Cells)
    {
        std::cout << numberLabel << "│";
        for (const auto cell : rows)
        {
            std::cout << cell->GetValue() << "│";
        }
        std::cout << numberLabel-- << std::endl;
        if (numberLabel > 0)
        {
            std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
        }
    }
    std::cout << " └───┴───┴───┴───┴───┴───┴───┴───┘ " <<std::endl;
    std::cout << "   A   B   C   D   E   F   G   H   " <<std::endl;
}