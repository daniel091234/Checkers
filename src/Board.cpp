#include <iostream>

#include "Board.hpp"

Board::Board(const size_t& size) : m_Size(size)
{

}

void Board::Draw()
{
    std::cout << "   A   B   C   D   E   F   G   H" <<std::endl;
    std::cout << " ┌───┬───┬───┬───┬───┬───┬───┬───┐" <<std::endl;
    std::cout << "8│   │ B │   │ B │   │ B │   │ B │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "7│ B │   │ B │   │ B │   │ B │   │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "6│   │ B │   │ B │   │ B │   │ B │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "5│   │   │   │   │   │   │   │   │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "4│   │   │   │   │   │   │   │   │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "3│ w │   │ w │   │ w │   │ w │   │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "2│   │ W │   │ W │   │ W │   │ W │" <<std::endl;
    std::cout << " ├───┼───┼───┼───┼───┼───┼───┼───┤" <<std::endl;
    std::cout << "1│ W │   │ W │   │ W │   │ W │   │" <<std::endl;
    std::cout << " └───┴───┴───┴───┴───┴───┴───┴───┘" <<std::endl;
}

const size_t& Board::GetSize() const 
{
    return m_Size;
}