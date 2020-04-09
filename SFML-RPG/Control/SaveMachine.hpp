////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

#ifndef SFML_RPG_SAVEMACHINE
#define SFML_RPG_SAVEMACHINE

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <SFML\Graphics.hpp>

#include "Character\Player.hpp"
#include "WorldItems\World.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	/// \brief Controls saving/loading of Players and Worlds
	///
	////////////////////////////////////////////////////////////
	class SaveMachine
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Initializes member variables
		///
		////////////////////////////////////////////////////////////
		SaveMachine();

		////////////////////////////////////////////////////////////
		/// \brief Destructor
		///
		////////////////////////////////////////////////////////////
		~SaveMachine();

		////////////////////////////////////////////////////////////
		/// \brief Splits a string into a vector of strings
		///
		/// \param split string to split
		/// \param delimeter character to split on
		///
		/// \return a vector with strings split using the delimeter
		///
		////////////////////////////////////////////////////////////
		std::vector<std::string> split(std::string split, char delimeter);

		////////////////////////////////////////////////////////////
		/// \brief Loads a player based on a path
		///
		/// \param path location of save file
		///
		/// \return a player with the save file's information
		///
		////////////////////////////////////////////////////////////
		Player load_player(std::string path);

		////////////////////////////////////////////////////////////
		/// \brief Loads a world based on a path
		///
		/// \param path location of save file
		///
		/// \return a world with the save file's information
		///
		////////////////////////////////////////////////////////////
		World load_world(std::string path);

		////////////////////////////////////////////////////////////
		/// \brief Saves a player to a given file
		///
		/// \param path location of save file
		/// \param player to save
		///
		////////////////////////////////////////////////////////////
		void save_player(std::string path, Player player);

		////////////////////////////////////////////////////////////
		/// \brief Saves a world to a given file
		///
		/// \param path location of save file
		/// \param world to save
		///
		////////////////////////////////////////////////////////////
		void save_world(std::string path, World world);

	private:

		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		std::ifstream in;  ///< Stream used for loading
		std::ofstream out; ///< Stream used for saving

	};

} // namespace rpg

#endif // SFML_RPG_SAVEMACHINE
