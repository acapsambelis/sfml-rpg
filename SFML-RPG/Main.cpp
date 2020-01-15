#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ObjectDisperse.h"
#include "WorldObject.h"
#include "World.h"
#include "Gui.h"

#include <iostream>
#include <vector>

int main()
{
	// WINDOW AND VIEW CREATION //
	sf::VideoMode currentMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window;
	window.create(currentMode, "Title", sf::Style::Fullscreen);

	sf::View worldView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 450));

	sf::View guiView(sf::Vector2f(10000.0f, 10000.0f), sf::Vector2f(800.0f, 450.0f));

	// ITEMDISPERSE CREATION //
	std::vector<WorldObject> collItems;
	std::vector<WorldObject> worldI;
	int ID = 0;
	// Grass
	sf::Texture grBlade;
	grBlade.loadFromFile("ImageRec/grass_blade.png");
	sf::Texture grEnt;
	grEnt.loadFromFile("ImageRec/grass_blade.png");

	WorldObject grass("Grass", 00, &grBlade, &grEnt,
		2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(0.0f, 0.0f));
	ObjectDisperse grs(grass, sf::Vector2f(1000, 1000), 0.5f);
	std::vector<WorldObject> gr = grs.Disperse(1u);
	for (unsigned int i = 0; i < gr.size(); i++) {
		worldI.push_back(gr[i]);
	}
	ID += 1 + gr.size();

	// Stump
	sf::Texture stumpTxtr;
	stumpTxtr.loadFromFile("ImageRec/pixel_stump.png");
	sf::Texture stumpEnt;
	stumpEnt.loadFromFile("ImageRec/pixel_stump.png");

	WorldObject stump("Stump", 00, &stumpTxtr, &stumpEnt,
		2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(0.0f, 0.0f));
	ObjectDisperse stp(stump, sf::Vector2f(1000, 1000), 0.5f);
	std::vector<WorldObject> st = stp.Disperse(ID);
	for (unsigned int i = 0; i < st.size(); i++) {
		worldI.push_back(st[i]);
		collItems.push_back(st[i]);
	}
	ID += 1 + st.size();
	
	// WORLD CREATION //
	sf::Texture ground;
	ground.loadFromFile("ImageRec/pixel_grass.png");
	World wrld(&ground, worldI, collItems);
	
	// PLAYER CREATION //
	sf::Texture playerTexture;
	playerTexture.loadFromFile("ImageRec/player_texture.png");

	Player player(/*Identity*/ wrld, "Player", 0, 
		/*Txtr & animation*/ &playerTexture, 2, true, sf::Vector2u(1, 1), 0.0f,
		/*weight*/ 0.5f, /*strength*/ 1.0f,
		/*Position*/ sf::Vector2f(250.0f, 250.0f), /*Speed*/ 200.0f);

	// GUI CREATION //
	/**/
	sf::RectangleShape healthbar;
	healthbar.setSize(sf::Vector2f(player.health, 10.0f));
	healthbar.setPosition(9620.0f, 9800.0f);
	healthbar.setFillColor(sf::Color(0, 0, 255));
	sf::Vector2f pos = healthbar.getPosition();
	
	Gui g(healthbar);
	g.elements.push_back(healthbar);
	
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		// UPDATE //
		player.Update(deltaTime);

		for (unsigned int i = 0; i < wrld.collideables.size(); ++i)
		{
			player.Collide(wrld.collideables[i], wrld.collideables);
		}

		// DISPLAY //
		window.clear(sf::Color(150, 150, 150));
		/**/
		worldView.setCenter(player.GetPosition());
		window.setView(worldView);
		wrld.Draw(window);
		for (unsigned int i = 0; i < wrld.worldItems.size(); ++i)
		{
			window.draw(wrld.worldItems[i].body);
		}
		player.Draw(window);
		
		// UI //
		g.Update(player);
		window.setView(guiView);
		g.Draw(window);
		
		window.display();

	}

	return 0;
}