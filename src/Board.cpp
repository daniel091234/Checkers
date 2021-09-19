#include <iostream>

#include "Board.hpp"
#include "Cell.hpp"

Board::Board(const size_t& size) : m_Size(size)
{
    m_Cells.reserve(m_Size);
    for (int x = 0; x < m_Size; x++)
    {
        std::vector<std::shared_ptr<ICell>> row(m_Size);
        for (int y = 0; y < m_Size; y++)
        {
            row.push_back(std::make_shared<Cell>());
        }
        m_Cells.push_back(row);
    }
}

void Board::Draw()
{
    std::cout << "   A   B   C   D   E   F   G   H   " <<std::endl;
    std::cout << " ┌───┬───┬───┬───┬───┬───┬───┬───┐ " <<std::endl;
    std::cout << "8│   │ b │   │ b │   │ b │   │ b │8" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "7│ b │   │ b │   │ b │   │ b │   │7" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "6│   │ b │   │ b │   │ b │   │ b │6" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "5│   │   │   │   │   │   │   │   │5" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "4│   │   │   │   │   │   │   │   │4" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "3│ w │   │ w │   │ w │   │ w │   │3" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "2│   │ w │   │ w │   │ w │   │ w │2" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤ " <<std::endl;
    std::cout << "1│ w │   │ w │   │ w │   │ w │   │1" <<std::endl;
    std::cout << " └───┴───┴───┴───┴───┴───┴───┴───┘ " <<std::endl;
    std::cout << "   A   B   C   D   E   F   G   H   " <<std::endl;

}

const size_t& Board::GetSize() const 
{
    return m_Size;
}