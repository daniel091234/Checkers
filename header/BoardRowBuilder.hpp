#pragma once

#include <string>

#include "IBoardRowBuilder.hpp"

class BoardRowBuilder : public IBoardRowBuilder
{
public:
    BoardRowBuilder(const size_t&);
    ~BoardRowBuilder() = default;
    std::string GetTopSide();
    std::string GetBottomSide();
    std::string GetMiddleSide(const std::string&,
                              const uint8_t);
private:
    std::string GetSide(const std::string[3]) const;
    std::string GetCellSide(const std::string, const std::string, const std::string) const;
    std::string GetLetterLabel() const;
    std::string GetLetters() const;
    std::string m_StartingSpace;
    std::string m_LetterLabel;
    const size_t m_Size;
};