#include <SFML/Graphics.hpp>
#include "Character\Player.h"
#include "WorldItems\ObjectDisperse.h"
#include "WorldItems\WorldObject.h"
#include "WorldItems\World.h"
#include "Control\Gui.h"

#include <iostream>
#include <unordered_set>

int main()
{
	// WINDOW AND VIEW CREATION //
	sf::VideoMode currentMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window;
	window.create(currentMode, "Title", sf::Style::Fullscreen);

	sf::View worldView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 450));
	sf::View guiView(sf::Vector2f(10000.0f, 10000.0f), sf::Vector2f(800.0f, 450.0f));

	// ITEMDISPERSE CREATION //
	std::unordered_set<WorldObject, MyHashFunction> collSet;
	std::unordered_set<WorldObject, MyHashFunction> worldSet;

	int ID = 0;
	// Grass
	sf::Texture grBlade;
	grBlade.loadFromFile("ImageRec/grass_blade.png");
	sf::Texture grEnt;
	grEnt.loadFromFile("ImageRec/grass_blade.png");
	/**/
	WorldObject grass(
		/*Metadata*/ "Grass", 00, sf::Vector2f(0.0f, 0.0f),
		/*Textures*/ &grBlade, &grEnt,
		/*Collision*/ 0.0f,
		/*Animation*/ 2.0f, true, sf::Vector2u(1, 1), 0.0f
	);

	ObjectDisperse grs(grass, sf::Vector2f(1000, 1000), 0.5f);
	ID = grs.Disperse(1, worldSet);

	// Stump
	sf::Texture stumpTxtr;
	stumpTxtr.loadFromFile("ImageRec/pixel_stump.png");
	sf::Texture stumpEnt;
	stumpEnt.loadFromFile("ImageRec/pixel_stump.png");
	/**/
	WorldObject stump(
		/*Metadata*/ "Stump", 00, sf::Vector2f(0.0f, 0.0f),
		/*Textures*/ &stumpTxtr, &stumpEnt,
		/*Collision*/ 1.0f,
		/*Animation*/ 2.0f, true, sf::Vector2u(1, 1), 0.0f
	);
	ObjectDisperse stp(stump, sf::Vector2f(1000, 1000), 0.5f);
	ID = stp.Disperse(ID, worldSet, collSet);

	// WORLD CREATION //
	sf::Texture ground;
	ground.loadFromFile("ImageRec/pixel_grass.png");
	World wrld(&ground, worldSet, collSet);


	// PLAYER CREATION //
	sf::Texture playerTexture;
	playerTexture.loadFromFile("ImageRec/player_texture.png");

	Player player(
		/*Metadata*/ wrld, "Player", 0, sf::Vector2f(250.0f, 250.0f),
		/*Texture*/ &playerTexture,
		/*Collision*/ 0.5f,
		/*Animation*/ 2, true, sf::Vector2u(1, 1), 0.0f,
		/*Character*/ 100.0f, 200.0f, 1.0f
	);



	// GUI CREATION //
	sf::RectangleShape healthbar;
	healthbar.setSize(sf::Vector2f(player.health, 10.0f));
	healthbar.setPosition(9620.0f, 9800.0f);
	healthbar.setFillColor(sf::Color(0, 0, 255));
	sf::Vector2f pos = healthbar.getPosition();

	Gui g(healthbar);
	
	float deltaTime = 0.0f;
	sf::Clock clock;

	while(window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		// UPDATE //
		player.Update(deltaTime);
		bool completed = false;
		while(!completed)
		{
			for(auto obj : wrld.collideables)
			{
				bool mined = player.Collide(obj, worldView);
				if(mined)
				{
					wrld.collideables.erase(obj);
					wrld.worldItems.erase(obj);
					completed = false;
					break;
				} else {
					completed = true;
				}
			}
		}

		// DISPLAY //
		window.clear(sf::Color(150, 150, 150));
		
		worldView.setCenter(player.GetPosition());
		window.setView(worldView);
		wrld.Draw(window);
		for(auto obj : wrld.worldItems)
		{
			obj.Draw(window, worldView);
		}
		player.Draw(window, worldView);
		
		// UI //
		g.Update(player);
		window.setView(guiView);
		g.Draw(window);
		
		window.display();
	}
	return 0;
}