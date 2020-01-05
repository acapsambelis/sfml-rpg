#include <SFML/Graphics.hpp>
#include "Player.h"
#include "WorldObject.h"
#include "World.h"

#include <iostream>

int main()
{
	// WINDOW AND VIEW CREATION //
	sf::VideoMode currentMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window;
	window.create(currentMode, "Title", sf::Style::Fullscreen);

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 450));

	// PLAYER AND WORLDITEM CREATION //
	std::vector<WorldObject> worldItems;
	sf::RectangleShape boxRect;
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("ImageRec/player_texture.png");

	Player player(0u, boxRect, &playerTexture, 2, true, sf::Vector2u(1, 1), 0.0f,
		/*weight*/ 0.5f,
		/*strength*/ 1.0f,
		sf::Vector2f(250.0f, 250.0f), 200.0f);
	worldItems.push_back(player);

	sf::Texture boxTexture;
	boxTexture.loadFromFile("ImageRec/box.png");
	sf::Texture ironBoxTexture;
	ironBoxTexture.loadFromFile("ImageRec/iron_box.png");

	WorldObject immove(1u, &ironBoxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 1.0f, sf::Vector2f(500.0f, 200.0f));
	worldItems.push_back(immove);
	
	WorldObject move(2u, &boxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 0.0f, sf::Vector2f(500.0f, 0.0f));
	worldItems.push_back(move);
	
	WorldObject move2(3u, &boxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 0.0f, sf::Vector2f(500.0f, 100.0f));
	worldItems.push_back(move2);


	// WORLD CREATION //
	sf::Texture ground;
	ground.loadFromFile("ImageRec/ground_terrain.png");
	World wrld(&ground, worldItems);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		player.Update(deltaTime);

		for (unsigned int i = 1; i < wrld.worldItems.size(); ++i)
		{
			player.UpdateCollision(wrld.worldItems[i], wrld.worldItems);
		}

		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		wrld.Draw(window);
		player.Draw(window);
		for (unsigned int i = 1; i < wrld.worldItems.size(); ++i)
		{
			wrld.worldItems[i].Draw(window);
		}

		window.display();

	}

	return 0;
}