#include <sstream>

#include "BoardRowBuilder.hpp"

BoardRowBuilder::BoardRowBuilder(const size_t& size) : m_Size(size)
{

}

std::string BoardRowBuilder::GetTopSide()
{
    return GetLabel() + GetSide(" ┌──", "─┬──", "─┐ ");
}
std::string BoardRowBuilder::GetBottomSide()
{
    return GetSide(" └──", "─┴──", "─┘ ") + GetLabel();
}

std::string BoardRowBuilder::GetMiddleSide(const std::vector<std::shared_ptr<ICell>>& rows,
                                           const uint8_t numberLabel)
{
    // Removed the label from the left for now
    // To re add number label and account for the digit space
    // Will use to_string(m_Size).size();
    std::stringstream ss;
    ss << " │";
    for (const auto cell : rows)
    {
        ss << " " << cell->GetValue() << " │";
    }
    ss << " " << std::to_string(numberLabel) << std::endl;

    if (numberLabel > 1)
    {
        ss << GetSide(" ├──", "─┼──", "─┤ ");
    }

    return ss.str();
}

std::string BoardRowBuilder::GetSide(const std::string& leftPiece,
                                     const std::string& middlePiece,
                                     const std::string& rightPiece) const
{
    std::stringstream ss;
    
    ss << leftPiece;
    for (int x = 0; x < m_Size - 1; x++)
    {
        ss << middlePiece;
    }
    ss << rightPiece << std::endl;

    return ss.str();
}

std::string BoardRowBuilder::GetLabel() const
{
    std::stringstream ss;

    ss << "  ";
    for (int x = 0; x < m_Size; x++)
    {
        const char label = 'A' + x;
        ss << " " << label << "  ";
    }
    ss << " " << std::endl;

    return ss.str();
}