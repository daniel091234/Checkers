#pragma once

#include <string>

class IPlayer
{
public:
    const virtual std::string& GetName() const = 0;
};
