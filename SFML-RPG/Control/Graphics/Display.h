#pragma once
#include <SFML\Graphics.hpp>
#include "..\..\Character\Player.h"
#include "..\..\WorldItems\World.h"
#include "Gui.h"

class Display
{
public:
	Display();
	~Display();

	void InitializePlayer(Player& player);
	void InitializeWorld(World& world);

	void TickReset(Player player);
	void DrawTick(Player player, World world);

	void Close();

private:
	sf::VideoMode currentMode;
	sf::RenderWindow window;

	sf::View worldView;
	sf::View guiView;

	sf::Texture atlas;

	Gui gui;

};

