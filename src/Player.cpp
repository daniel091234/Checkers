#include "Player.hpp"

Player::Player(const std::string& name) : m_Name(name)
{

}

std::string Player::GetName()
{
    return m_Name;
}

