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
    std::stringstream ss;
    ss << " │";
    for (const auto cell : rows)
    {
        ss << " " << cell->GetValue() << " │";
    }
    ss << numberLabel << std::endl;

    if (numberLabel > 0)
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

std::string BoardRowBuilder::GetMiddleFiller() const
{
    return GetSide(" ├──", "─┼──", "─┤ ");
}
