#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ItemDisperse.h"
#include "WorldObject.h"
#include "World.h"

#include <iostream>
#include <vector>

int main()
{
	// WINDOW AND VIEW CREATION //
	sf::VideoMode currentMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window;
	window.create(currentMode, "Title", sf::Style::Fullscreen);

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 450));

	// PLAYER CREATION //
	std::vector<WorldObject> collItems;
	std::vector<WorldObject> worldI;
	unsigned int ID = 0;

	sf::Texture playerTexture;
	playerTexture.loadFromFile("ImageRec/player_texture.png");

	Player player(0u, &playerTexture, 2, true, sf::Vector2u(1, 1), 0.0f,
		/*weight*/ 0.5f,
		/*strength*/ 1.0f,
		sf::Vector2f(250.0f, 250.0f), 200.0f);
	worldI.push_back(player);
	
	// ITEMDISPERSE CREATION //

	// Grass
	sf::Texture grBlade;
	grBlade.loadFromFile("ImageRec/grass_blade.png");
	WorldObject grass(00u, &grBlade, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(0.0f, 150.0f));
	ItemDisperse grs(grass, sf::Vector2f(1000, 1000), 0.5f);
	std::vector<WorldObject> gr = grs.Disperse(1u);
	for (unsigned int i = 0; i < gr.size(); i++) {
		worldI.push_back(gr[i]);
	}
	ID += gr.size();

	// Stump
	/**/
	sf::Texture stumpTxtr;
	stumpTxtr.loadFromFile("ImageRec/pixel_stump.png");
	WorldObject stump(00u, &stumpTxtr, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(0.0f, 150.0f));
	ItemDisperse stp(stump, sf::Vector2f(1000, 1000), 0.5f);
	std::vector<WorldObject> st = stp.Disperse(1u);
	for (unsigned int i = 0; i < st.size(); i++) {
		worldI.push_back(st[i]);
		collItems.push_back(st[i]);
	}
	ID += st.size();


	// WORLDOBJECTS //
	/*
	sf::Texture boxTexture;
	boxTexture.loadFromFile("ImageRec/box.png");
	sf::Texture ironBoxTexture;
	ironBoxTexture.loadFromFile("ImageRec/iron_box.png");

	WorldObject immove(ID+1u, &ironBoxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(500.0f, 200.0f));
	collItems.push_back(immove);
	worldI.push_back(immove);
	
	WorldObject move(ID+2u, &ironBoxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(500.0f, 0.0f));
	collItems.push_back(move);
	worldI.push_back(move);
	
	WorldObject move2(ID+3u, &ironBoxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(500.0f, 100.0f));
	collItems.push_back(move2);
	worldI.push_back(move2);
	*/

	// WORLD CREATION //
	sf::Texture ground;
	ground.loadFromFile("ImageRec/pixel_grass.png");
	World wrld(&ground, worldI, collItems);

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
			player.UpdateCollision(wrld.collideables[i]);
		}

		// DISPLAY //
		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		wrld.Draw(window);
		for (unsigned int i = 1; i < wrld.worldItems.size(); ++i)
		{
			wrld.worldItems[i].Draw(window);
		}
		player.Draw(window);

		window.display();

	}

	return 0;
}