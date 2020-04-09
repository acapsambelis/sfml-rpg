////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

#ifndef SFML_RPG_CONTROL
#define SFML_RPG_CONTROL

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Logic\Game.hpp"
#include "Graphics\Display.hpp"
#include "SaveMachine.hpp"
#include "Character\Player.hpp"
#include "WorldItems\World.hpp"
#include "WorldItems\WorldObject.hpp"
#include "WorldItems\ObjectDisperse.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	/// \brief Logical model for the demo
	///
	////////////////////////////////////////////////////////////
	class Control
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Initializes boolean member variables
		///
		////////////////////////////////////////////////////////////
		Control();

		////////////////////////////////////////////////////////////
		/// \brief Destructor
		///
		////////////////////////////////////////////////////////////
		~Control();

		////////////////////////////////////////////////////////////
		/// \brief Initializes player from a save file
		///
		/// Initializes using the save_machine.
		/// The file loaded is :
		///     "Saves/Player.arpg"
		/// The program will crash if this file does not exist.
		/// The file "Saves/PlayerBackup.arpg" has a working version
		/// of a player save in the event that the main file
		/// no longer exists.
		///
		////////////////////////////////////////////////////////////
		void initialize_player();

		////////////////////////////////////////////////////////////
		/// \brief Initializes world from a save file
		///
		/// Initializes using the save_machine.
		/// The file loaded is :
		///     "Saves/World.arpg"
		/// The program will crash if this file does not exist.
		/// The file "Saves/WorldBackup.arpg" has a working version
		/// of a world save in the event that the main file
		/// no longer exists.
		///
		////////////////////////////////////////////////////////////
		void initialize_world();

		////////////////////////////////////////////////////////////
		/// \brief The main game loop
		///
		/// Updates player and world,
		/// Draws changes to the screen,
		/// Checks for reloads and closes.
		///
		////////////////////////////////////////////////////////////
		void loop();

		////////////////////////////////////////////////////////////
		/// \brief Generates a new world
		///
		/// Resets player and world,
		/// Uses ObjectDisperses to add Objects
		///
		////////////////////////////////////////////////////////////
		void reload();

		////////////////////////////////////////////////////////////
		/// \brief Saves player and world
		///
		/// Like loading, the files:
		///     "Saves/Player.arpg"
		///		"Saves/World.arpg"
		/// must exist for saving to work
		///
		////////////////////////////////////////////////////////////
		void save();

		////////////////////////////////////////////////////////////
		/// \brief Initializes, then starts loop
		///
		/// When requested, reloads and closes properly
		///
		////////////////////////////////////////////////////////////
		void play();

	private:

		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		bool        playing;       ///< Keeps track of if the game is still running
		bool        new_world_gen; ///< Does the player request a new world
		Player      player;        ///< Player for user to manipulate
		World       world;         ///< World to interact with
		SaveMachine save_machine;  ///< For saving/loading
		Game        game;          ///< Runs input gathering and updating
		Display     display;       ///< Abstracts away graphical changes
	};

} // namespace rpg

#endif // SFML_RPG_CONTROL
