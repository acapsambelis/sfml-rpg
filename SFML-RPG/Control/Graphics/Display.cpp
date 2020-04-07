#include "Display.h"

#define LOG(n) std::cout << n << std::endl;

Display::Display()
{
	// WINDOW //
	this->currentMode = sf::VideoMode::getDesktopMode();
	this->window.create(currentMode, "SFML-RPG", sf::Style::Fullscreen);

	// VIEWS //
	this->worldView = sf::View(
		/*Center*/ sf::Vector2f(0.0f, 0.0f),
		/*Size*/ sf::Vector2f(currentMode.width / 8.0f,
			currentMode.height / 8.0f));
	this->guiView = sf::View(
		/*Center*/ sf::Vector2f(0.0f, 0.0f),
		/*Size*/ sf::Vector2f(currentMode.width / 8.0f,
			currentMode.height / 8.0f));

	// RESOURCE MANAGER //
	this->atlas = sf::Texture();
	atlas.loadFromFile("ImageRec/atlas.png");

	// GUI //
	this->gui.Initialize(this->guiView);
}

Display::~Display()
{
}

void Display::InitializePlayer(Player& player)
{
	player.SetSprite(atlas);
}

void Display::InitializeWorld(World& world)
{
	world.SetSprite(atlas);
	world.SetScale(1000.0f, 1000.0f);
	world.SetObjSprite(atlas);
}


void Display::TickReset(Player player)
{
	window.clear(sf::Color(150, 150, 150));

	worldView.setCenter(player.getPosition());
	window.setView(worldView);
}

void Display::DrawTick(Player player, World world)
{
	world.Draw(window, worldView, true);
	for (int i = 0; i < world.worldItems.size(); i++)
	{
		world.worldItems[i].Draw(window, worldView);
	}
	player.Draw(window, worldView);
	
	gui.Update(player);
	window.setView(guiView);
	gui.Draw(window);

	window.display();
}

void Display::Close()
{
	window.close();
}
