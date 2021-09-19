#pragma once

#include <string>

class ICell
{
public:
    const virtual std::string GetValue() const = 0;
};
