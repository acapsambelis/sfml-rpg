#include "Gui.h"

namespace rpg {

	Gui::Gui()
	{
	}

	Gui::~Gui()
	{
	}

	void Gui::Initialize(sf::View guiView)
	{
		this->guiView = guiView;

		healthbar = sf::RectangleShape();
		healthbar.setPosition(
			this->guiView.getCenter()
			- (this->guiView.getSize() / 2.0f)
			+ PIXELBUFFER
		);
		healthbar.setFillColor(sf::Color(0, 0, 255));
		sf::Vector2f pos = healthbar.getPosition();
	}

	void Gui::Draw(sf::RenderWindow& window)
	{
		window.draw(healthbar);
	}

	void Gui::Update(Player player)
	{
		healthbar.setSize(sf::Vector2f(player.getHealth(), 8.0f));
	}
}
