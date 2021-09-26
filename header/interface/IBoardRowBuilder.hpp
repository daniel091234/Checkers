#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ICell.hpp"

class IBoardRowBuilder
{
public:
    virtual std::string GetTopSide() = 0;
    virtual std::string GetBottomSide() = 0;
    virtual std::string GetMiddleSide(const std::string&, const uint8_t) = 0;
};

