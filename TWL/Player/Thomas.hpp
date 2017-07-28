#pragma once
#include "Player.hpp"

class Thomas : public Player
{
public:
    // A constructor specific to Thomas
    Thomas();
    
    // The overridden input handler for Thomas
    bool virtual handleInput();
    
};
