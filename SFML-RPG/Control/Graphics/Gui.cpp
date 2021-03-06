////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Gui.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	Gui::Gui()
	{
	}

	////////////////////////////////////////////////////////////
	Gui::~Gui()
	{
	}

	////////////////////////////////////////////////////////////
	void Gui::initialize(sf::View gui_view)
	{
		this->gui_view = gui_view;

		healthbar = sf::RectangleShape();
		healthbar.setPosition(
			this->gui_view.getCenter()
			- (this->gui_view.getSize() / 2.0f)
			+ PIXELBUFFER
		);
		healthbar.setFillColor(sf::Color(0, 0, 255));
		sf::Vector2f pos = healthbar.getPosition();
	}

	////////////////////////////////////////////////////////////
	void Gui::draw(sf::RenderWindow& window)
	{
		window.draw(healthbar);
	}

	////////////////////////////////////////////////////////////
	void Gui::update(Player player)
	{
		healthbar.setSize(sf::Vector2f(player.get_health(), 8.0f));
	}

} // namespace rpg
