#include "SaveMachine.h"

SaveMachine::SaveMachine()
{
	this->in = std::ifstream();
	this->out = std::ofstream();
}

SaveMachine::~SaveMachine()
{
}

std::vector<std::string> SaveMachine::Split(std::string split, char delimeter)
{
	std::stringstream ss(split);
	std::string item;
	std::vector<std::string> splittedStrings;
	while (std::getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

//"../Saves/Test.txt"
Player SaveMachine::loadPlayer(std::string path)
{
	in.open(path);
	if (!in) 
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}

	std::string name;
	in >> name;

	std::string id;
	in >> id;

	std::string pos;
	in >> pos;
	std::vector<std::string> posTokens = Split(pos, ',');

	std::string rect;
	in >> rect;
	std::vector<std::string> rectTokens = Split(rect, ',');

	std::string health;
	in >> health;

	std::string speed;
	in >> speed;

	in.close();
	return Player(name, std::stoi(id), sf::Vector2f(std::stof(posTokens[0]), std::stof(posTokens[1])),
		sf::IntRect(std::stof(rectTokens[0]), std::stof(rectTokens[1]), std::stof(rectTokens[2]), std::stof(rectTokens[3])),
		std::stof(health), std::stof(speed));
}

World SaveMachine::loadWorld(std::string path)
{
	return World();
}

void SaveMachine::savePlayer(std::string path, Player player)
{
	out.open(path);
	if (!out)
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	out << player.GetWriteable();

	out.close();
}

void SaveMachine::saveWorld(std::string path, World world)
{
}
