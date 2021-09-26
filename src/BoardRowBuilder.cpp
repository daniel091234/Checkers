#include <sstream>
#include <algorithm>

#include "BoardRowBuilder.hpp"

namespace 
{
    const std::string TOP_PIECES[3] = { "┌──", "─┬──", "─┐"};
    const std::string MID_PIECES[3] = { "├──", "─┼──", "─┤"};
    const std::string BOT_PIECES[3] = { "└──", "─┴──", "─┘"};
    constexpr auto SPACE = " ";
    constexpr auto EMPTY = "";
    constexpr auto EDGE_PIECE = "│";
    constexpr auto START_LABEL = 'A';
}

BoardRowBuilder::BoardRowBuilder(const size_t& size) : 
    m_Size(size)
{
    m_LetterLabel = GetLetterLabel();
    const auto& numOfDigits = std::to_string(m_Size).size();
    m_StartingSpace = std::string(SPACE, numOfDigits);
}

std::string BoardRowBuilder::GetTopSide()
{
    return m_LetterLabel + GetSide(TOP_PIECES);
}
std::string BoardRowBuilder::GetBottomSide()
{
    return GetSide(BOT_PIECES) + m_LetterLabel;
}

std::string BoardRowBuilder::GetMiddleSide(const std::string& row,
                                           const uint8_t rowCtr)
{
    std::stringstream ss;
    const auto& numLabel = std::to_string(rowCtr);

    ss << numLabel << SPACE;

    ss << GetCellSide(EDGE_PIECE, numLabel, row);

    if (rowCtr > 1)
    {
        ss << GetSide(MID_PIECES);
    }

    return ss.str();
}

std::string BoardRowBuilder::GetSide(const std::string pieces[3]) const
{
    std::stringstream ss;
    
    ss << SPACE << SPACE;
    ss << pieces[0];
    for (int x = 0; x < m_Size - 1; x++)
    {
        ss << pieces[1];
    }
    ss << pieces[2] << SPACE << std::endl;

    return ss.str();
}

std::string BoardRowBuilder::GetLetterLabel() const
{
    std::stringstream ss;

    std::string values = GetLetters();

    ss << SPACE << SPACE;
    ss << GetCellSide(SPACE, EMPTY, values);

    return ss.str();
}

std::string BoardRowBuilder::GetCellSide(const std::string side, const std::string end, const std::string values) const
{
    std::stringstream ss;

    ss << side;

    for (const auto value : values)
    {
        ss << SPACE << value << SPACE << side;
    }
    ss << SPACE << end << std::endl;

    return ss.str();
}

std::string BoardRowBuilder::GetLetters() const
{
    std::stringstream ss;
    for (int x = START_LABEL; x < START_LABEL + m_Size; x++)
    {
        ss << (char) x;
    }
    return ss.str();
}