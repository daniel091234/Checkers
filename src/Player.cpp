#include "Player.hpp"

Player::Player(const std::string& name) : m_Name(name)
{

}

const std::string& Player::GetName() const
{
    return m_Name;
}

