#include "Draw.h"

void DrawScr(sf::RenderWindow& window, sf::View view, World world, Player player, WorldObject obstacle1, WorldObject& obstacle2)
{
	window.clear(sf::Color(150, 150, 150));
	window.setView(view);
	world.Draw(window);
	player.Draw(window);
	obstacle1.Draw(window);
	obstacle2.Draw(window);
	window.display();
}