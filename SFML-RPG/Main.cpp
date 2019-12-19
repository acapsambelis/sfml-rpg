#include <SFML/Graphics.hpp>
#include "Player.h"
#include "worldObject.h"
#include "World.h"

#include "Draw.h"


int main()
{
	sf::VideoMode currentMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window;
	window.create(currentMode, "Title", sf::Style::Fullscreen);

	sf::Texture ground;
	ground.loadFromFile("ImageRec/ground_terrain.png");
	World wrld(&ground);


	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 450));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("ImageRec/player_texture.png");

	Player player(&playerTexture, true, sf::Vector2u(1, 1), 0.3f, 200.0f);

	sf::Texture boxTexture;
	boxTexture.loadFromFile("ImageRec/box.png");
	WorldObject obstacle1(&boxTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 200.0f));
	WorldObject obstacle2(&boxTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(500.0f, 0.0f));


	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();


		player.Update(deltaTime);
		Collider coll = player.GetCollider();
		Collider obs1 = obstacle1.GetCollider();
		Collider obs2 = obstacle2.GetCollider();

		obstacle1.GetCollider().CheckCollision(coll, 1.0f);
		obstacle1.GetCollider().CheckCollision(obs2, 1.0f);
		obstacle2.GetCollider().CheckCollision(coll, 0.0f);
		obstacle2.GetCollider().CheckCollision(obs1, 0.0f);


		view.setCenter(player.GetPosition());
		DrawScr(window, view, wrld, player, obstacle1, obstacle2);

	}


	return 0;
};