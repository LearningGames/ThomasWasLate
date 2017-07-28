#pragma once
#include "Player.hpp"

class Bob : public Player
{
public:
    // A constructor specific to Bob
    Bob();
    
    // The overriden input handler for Bob
    bool virtual handleInput();
    
};
