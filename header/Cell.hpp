#pragma once

#include "ICell.hpp"

class Cell : public ICell
{
public:
    Cell() = default;
    ~Cell() = default;
    const std::string GetValue() const;
};
