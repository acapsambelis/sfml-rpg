////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

#ifndef SFML_RPG_DISPLAYABLE
#define SFML_RPG_DISPLAYABLE

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <SFML\Graphics.hpp>

namespace rpg {

	////////////////////////////////////////////////////////////
	/// \brief Object that can be drawn to a window with sprites
	///
	////////////////////////////////////////////////////////////
	class Displayable
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Creates an empty Displayable.
		///
		////////////////////////////////////////////////////////////
		Displayable();

		////////////////////////////////////////////////////////////
		/// \brief Construct the Displayable
		///
		/// Creates a full Displayable
		///
		/// \param texture_rect  Rectangle for texture
		/// \param position      Location in world
		///
		////////////////////////////////////////////////////////////
		Displayable(sf::IntRect texture_rect, sf::Vector2f position);

		////////////////////////////////////////////////////////////
		/// \brief Copy constructor
		///
		/// \param copy instance to copy
		///
		////////////////////////////////////////////////////////////
		Displayable(const Displayable& copy, sf::Vector2f position);

		////////////////////////////////////////////////////////////
		/// \brief Destructor
		///
		////////////////////////////////////////////////////////////
		~Displayable();

		////////////////////////////////////////////////////////////
		/// \brief Return the position of the displayable
		///
		/// \return sprite's position
		///
		////////////////////////////////////////////////////////////
		sf::Vector2f get_position() { return spr.getPosition(); }

		////////////////////////////////////////////////////////////
		/// \brief Return the size of the displayble
		///
		/// \return texture_rect's dimensions
		///
		////////////////////////////////////////////////////////////
		sf::Vector2f get_size() { 
			return sf::Vector2f((float)texture_rect.width,
								(float)texture_rect.height); 
		}

		////////////////////////////////////////////////////////////
		/// \brief Return the texture_rect of the displayable
		///
		/// \return texture_rect
		///
		////////////////////////////////////////////////////////////
		sf::IntRect get_rect() { return texture_rect; }

		////////////////////////////////////////////////////////////
		/// \brief Set the sprite's texture
		///
		/// \param text to set
		///
		////////////////////////////////////////////////////////////
		void set_sprite(sf::Texture& text);

		////////////////////////////////////////////////////////////
		/// \brief Set the sprite's scale
		///
		/// \param x_scale to set
		/// \param y_scale to set
		///
		////////////////////////////////////////////////////////////
		void set_scale(float x_scale, float y_scale);

		////////////////////////////////////////////////////////////
		/// \brief Finds if the displayable is inside the view
		///
		/// \param view  to check inside
		/// \param obj   Displayable in question
		///
		/// \return if the displayable is in the view
		///
		////////////////////////////////////////////////////////////
		bool in_view(sf::View view, Displayable* obj);

		////////////////////////////////////////////////////////////
		/// \brief Moves the displayable by a specified amount
		///
		/// \param dx x-displacement
		/// \param dy y-displacement
		///
		////////////////////////////////////////////////////////////
		void move(float dx, float dy);

		////////////////////////////////////////////////////////////
		/// \brief Draws the displayable to the window if in_view
		///
		/// \param window  to draw to
		/// \param vw      to check inside
		///
		////////////////////////////////////////////////////////////
		void draw(sf::RenderWindow& window, sf::View vw);

		////////////////////////////////////////////////////////////
		/// \brief Draws the displayable to the window if in_view
		///
		/// \param window  to draw to
		/// \param force   if true, this will be drawn even if out of view
		///
		////////////////////////////////////////////////////////////
		void draw(sf::RenderWindow& window, bool force);

		////////////////////////////////////////////////////////////
		/// \brief Return a saveable form of the WorldObject
		///
		/// \return string representation of WorldObject
		///
		////////////////////////////////////////////////////////////
		std::string GetWriteable();

	private:

		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		sf::Sprite  spr;          ///< Sprite for object
		sf::IntRect texture_rect; ///< Texture rectangle from atlas
	};

} // namespace rpg

#endif // SFML_RPG_DISPLAYABLE