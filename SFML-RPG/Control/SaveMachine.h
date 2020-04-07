#pragma once
#include <SFML\Graphics.hpp>
#include "..\Character\Player.h"
#include "..\WorldItems\World.h"
#include <fstream>
#include <sstream>
#include <vector>

class SaveMachine
{
public:
	SaveMachine();
	~SaveMachine();

	std::vector<std::string> Split(std::string split, char delimeter);

	Player loadPlayer(std::string path);
	World loadWorld(std::string path);

	void savePlayer(std::string path, Player player);
	void saveWorld(std::string path, World world);

private:
	std::ifstream in;
	std::ofstream out;

};

