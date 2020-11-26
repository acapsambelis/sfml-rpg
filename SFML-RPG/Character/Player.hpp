////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

#ifndef SFML_RPG_PLAYER
#define SFML_RPG_PLAYER

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>

#include <SFML\Graphics.hpp>

#include "Character.hpp"
#include "WorldItems\Block.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	/// \brief Object that the user controls and manipulates
	///
	////////////////////////////////////////////////////////////
	class Player : public Character
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Creates an empty Player.
		///
		////////////////////////////////////////////////////////////
		Player();

		////////////////////////////////////////////////////////////
		/// \brief Construct the Player
		///
		/// Creates a full Player
		///
		/// \param name          WorldObject name
		/// \param id            WorldObject Id number for comparing
		/// \param position      Displayable location in world
		/// \param texture_rect  Displayable rectangle for texture
		/// \param health        Character health for mining
		/// \param speed         Character speed scalar for movement
		///
		////////////////////////////////////////////////////////////
		Player(
			std::string name, int ID, sf::Vector2f position,
			sf::IntRect texture_rect,
			float health, float speed
		);

		////////////////////////////////////////////////////////////
		/// \brief Copy constructor
		///
		/// \param copy instance to copy
		/// \param id new instance id
		/// \param position new instance position
		///
		////////////////////////////////////////////////////////////
		Player(const Player& copy, int id, sf::Vector2f position);

		////////////////////////////////////////////////////////////
		/// \brief Destructor
		///
		////////////////////////////////////////////////////////////
		~Player();

		////////////////////////////////////////////////////////////
		/// \brief Return a saveable form of the player
		///
		/// \return string representation of player
		///
		////////////////////////////////////////////////////////////
		std::string get_writable();

		////////////////////////////////////////////////////////////
		/// \brief Collide the player with another object and mine
		///
		/// Collides the player.  If the player is in state 2,
		/// the player mines the object, damaging the player
		/// by 10.0f and then deletes the other object
		///
		/// \param other WorldObject the player is colliding with
		///
		/// \return bool if the player mined the other or not
		///
		////////////////////////////////////////////////////////////
		bool collide(Block& other);
	};

} // namespace rpg

#endif // SFML_RPG_PLAYER
