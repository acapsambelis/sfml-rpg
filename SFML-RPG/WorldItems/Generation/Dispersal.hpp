////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

#ifndef SFML_RPG_OBJECTDISPERSE
#define SFML_RPG_OBJECTDISPERSE

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <SFML\Graphics.hpp>

#include "WorldItems\Block.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	/// \brief Randomly distributes WorldObjects in an area
	///
	////////////////////////////////////////////////////////////
	class Dispersal
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief Construct the ObjectDisperse
		///
		/// Creates a full ObjectDisperse
		///
		/// \param obj         WorldObject that will be copied
		/// \param range       Range in world to add objects to
		/// \param popularity  Scalar for percent chance to copy
		///
		////////////////////////////////////////////////////////////
		Dispersal(Block obj, sf::Vector2f range, float popularity);

		////////////////////////////////////////////////////////////
		/// \brief Destructor
		///
		////////////////////////////////////////////////////////////
		~Dispersal();

		////////////////////////////////////////////////////////////
		/// \brief Populates the range with objects
		///
		/// \param id   Id to start using for next copy
		/// \param map  Map to add copies to
		///
		/// \return the next id to be added
		///
		////////////////////////////////////////////////////////////
		int disperse(int next_id,
			std::unordered_map<int, Block>& map);

		////////////////////////////////////////////////////////////
		/// \brief Populates the range with objects
		///
		/// Adds each object to the map, but also adds the ids
		/// to be stored for use in collisions
		///
		/// \param next_id Id to start using for next copy
		/// \param map     Map to add copies to
		/// \param set     Set to add collideable ids to
		///
		/// \return the next id to be added
		///
		////////////////////////////////////////////////////////////
		int disperse(int next_id,
			std::unordered_map<int, Block>& map,
			std::unordered_set<int>& set);

	private:

		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		Block  obj_reference; ///< Object to be copied
		sf::Vector2f range;         ///< Area that will be populated
		float        popularity;    ///< Scalar for how often object is copied
	};

} // namespace rpg

#endif // SFML_RPG_OBJECTDISPERSE
