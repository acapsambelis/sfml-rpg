#include "Gui.h"
#include <iostream>

Gui::Gui(sf::RectangleShape& hth) :
	health(hth)
{
}

Gui::~Gui()
{
}

void Gui::Draw(sf::RenderWindow& window)
{
	window.draw(health);
}

void Gui::Update(Player ply)
{
	health.setSize(sf::Vector2f(ply.health, 10.0f));
}
