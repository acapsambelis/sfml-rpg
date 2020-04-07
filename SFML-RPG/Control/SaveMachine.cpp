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
	in.open(path);
	if (!in)
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}

	std::string worldPos;
	in >> worldPos;
	std::vector<std::string> worldPosTokens = Split(worldPos, ',');

	std::string worldRect;
	in >> worldRect;
	std::vector<std::string> worldRectTokens = Split(worldRect, ',');

	std::string x;
	std::string name;
	std::string id;
	std::string pos;
	std::vector<std::string> posTokens;
	std::string rect;
	std::vector<std::string> rectTokens;
	WorldObject obj;

	std::unordered_map<int, WorldObject> worldItems;

	in >> x;
	do {
		in >> name;
		in >> id;		
		in >> pos;
		posTokens = Split(pos, ',');
		in >> rect;
		rectTokens = Split(rect, ',');

		obj = WorldObject(name, std::stoi(id), sf::Vector2f(std::stof(posTokens[0]), std::stof(posTokens[1])), 
			sf::IntRect(std::stof(rectTokens[0]), std::stof(rectTokens[1]),
						std::stof(rectTokens[2]), std::stof(rectTokens[3])));

		worldItems[std::stoi(id)] = obj;

		in >> x;
	} while (x.compare("-.") != 0);

	std::string coll;
	in >> coll;
	std::vector<std::string> collv = Split(coll, ',');

	std::unordered_set<int> collID;
	for (std::string id : collv)
	{
		collID.insert(std::stoi(id));
	}

	in.close();
	return World(
		sf::Vector2f(std::stof(worldPosTokens[0]), std::stof(worldPosTokens[1])),
		sf::IntRect(std::stof(worldRectTokens[0]), std::stof(worldRectTokens[1]), 
					std::stof(worldRectTokens[2]), std::stof(worldRectTokens[3])), 
		worldItems, collID);
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
	out.open(path);
	if (!out)
	{
		std::cout << "Unable to open file" << std::endl;
		exit(1);
	}
	out << world.GetWriteable();

	out.close();
}
