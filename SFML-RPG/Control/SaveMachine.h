#pragma once
#include <SFML\Graphics.hpp>
#include "..\Character\Player.h"
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

private:
	std::ifstream in;

};

