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
    std::string GetMiddleSide(const std::vector<std::shared_ptr<ICell>>&,
                              const uint8_t);
private:
    std::string GetSide(const std::string& leftPiece,
                        const std::string& middlePiece,
                        const std::string& rightPiece) const;
    std::string GetLabel() const;
    std::string GetMiddleFiller() const;
    size_t m_Size;
};