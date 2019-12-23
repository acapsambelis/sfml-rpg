#include <SFML/Graphics.hpp>
#include "Player.h"
#include "WorldObject.h"
#include "World.h"



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

	Player player(&playerTexture, 2, true, sf::Vector2u(1, 1), 0.0f, 
		/*strength*/ 1.0f,
		/*weight*/ 0.5f,
		sf::Vector2f(250.0f, 250.0f), 200.0f);

	sf::Texture boxTexture;
	boxTexture.loadFromFile("ImageRec/box.png");
	sf::Texture ironBoxTexture;
	ironBoxTexture.loadFromFile("ImageRec/iron_box.png");

	WorldObject immove(&ironBoxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 0.0f, 1.0f, sf::Vector2f(500.0f, 200.0f));
	WorldObject move(&boxTexture, 2.0f, true, sf::Vector2u(1, 1),
		0.0f, 0.0f, 0.0f, sf::Vector2f(500.0f, 0.0f));

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
		Collider playc = player.GetCollider();
		Collider imvc = immove.GetCollider();
		Collider mvc = move.GetCollider();

		Collider worldColliders[2] = { imvc, mvc };
		Collider one[1] = { imvc };
		Collider two[1] = { mvc };


		playc.UpdateCollision(mvc, one, 1);
		playc.UpdateCollision(imvc, two, 1);



		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		wrld.Draw(window);
		player.Draw(window);
		immove.Draw(window);
		move.Draw(window);
		window.display();

	}

	return 0;
}
