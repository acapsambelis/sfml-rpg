#pragma once
#include <SFML\Graphics.hpp>

class Keys
{
public:
	Keys(sf::Keyboard);
	~Keys();

private:
	sf::Keyboard key;
	bool pressed;
};

