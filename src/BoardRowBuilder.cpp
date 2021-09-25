#include <sstream>
#include <iomanip>

#include "BoardRowBuilder.hpp"

namespace 
{
    const std::string TOP_PIECES[3] = { "┌──", "─┬──", "─┐"};
    const std::string MID_PIECES[3] = { "├──", "─┼──", "─┤"};
    const std::string BOT_PIECES[3] = { "└──", "─┴──", "─┘"};
    constexpr auto SPACE = ' ';
    constexpr auto EDGE_PIECE = "│";
    constexpr auto START_LABEL = 'A';
}

BoardRowBuilder::BoardRowBuilder(const size_t& size) : m_Size(size)
{

}

std::string BoardRowBuilder::GetTopSide()
{
    return GetLetterLabel() + GetSide(TOP_PIECES);
}
std::string BoardRowBuilder::GetBottomSide()
{
    return GetSide(BOT_PIECES) + GetLetterLabel();
}

std::string BoardRowBuilder::GetMiddleSide(const std::vector<std::shared_ptr<ICell>>& rows,
                                           const uint8_t rowCtr)
{
    std::stringstream ss;
    const auto& numLabel = std::to_string(rowCtr);

    ss << std::setw(GetNumLabelNoDigits()) << numLabel << SPACE << EDGE_PIECE;
    for (const auto cell : rows)
    {
        ss << SPACE << cell->GetValue() << SPACE << EDGE_PIECE;
    }
    ss << SPACE << numLabel << std::endl;

    if (rowCtr > 1)
    {
        ss << GetSide(MID_PIECES);
    }

    return ss.str();
}

std::string BoardRowBuilder::GetSide(const std::string pieces[3]) const
{
    std::stringstream ss;
    
    ss << SPACE << SPACE << pieces[0];
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

    ss << std::setw(4);
    for (int x = 0; x < m_Size; x++)
    {
        const char label = START_LABEL + x;
        ss << SPACE << label << SPACE << SPACE;
    }
    ss << std::endl;

    return ss.str();
}

size_t BoardRowBuilder::GetNumLabelNoDigits() const
{
    return std::to_string(m_Size).size();
}