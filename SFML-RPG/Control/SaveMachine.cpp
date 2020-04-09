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

#include "SaveMachine.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	SaveMachine::SaveMachine()
	{
		this->in = std::ifstream();
		this->out = std::ofstream();
	}

	////////////////////////////////////////////////////////////
	SaveMachine::~SaveMachine()
	{
	}

	////////////////////////////////////////////////////////////
	std::vector<std::string> SaveMachine::split(std::string split, char delimeter)
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

	////////////////////////////////////////////////////////////
	Player SaveMachine::load_player(std::string path)
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
		std::vector<std::string> posTokens = split(pos, ',');

		std::string rect;
		in >> rect;
		std::vector<std::string> rectTokens = split(rect, ',');

		std::string health;
		in >> health;

		std::string speed;
		in >> speed;

		in.close();
		return Player(name, std::stoi(id), sf::Vector2f(std::stof(posTokens[0]), std::stof(posTokens[1])),
			sf::IntRect(std::stoi(rectTokens[0]), std::stoi(rectTokens[1]), 
						std::stoi(rectTokens[2]), std::stoi(rectTokens[3])),
			std::stof(health), std::stof(speed));
	}

	////////////////////////////////////////////////////////////
	World SaveMachine::load_world(std::string path)
	{
		in.open(path);
		if (!in)
		{
			std::cout << "Unable to open file" << std::endl;
			exit(1);
		}

		std::string worldPos;
		in >> worldPos;
		std::vector<std::string> worldPosTokens = split(worldPos, ',');

		std::string worldRect;
		in >> worldRect;
		std::vector<std::string> worldRectTokens = split(worldRect, ',');

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
			if (name.compare("0"))
			{
				in >> id;
				in >> pos;
				posTokens = split(pos, ',');
				in >> rect;
				rectTokens = split(rect, ',');

				obj = WorldObject(name, std::stoi(id), sf::Vector2f(std::stof(posTokens[0]), std::stof(posTokens[1])),
					sf::IntRect(std::stoi(rectTokens[0]), std::stoi(rectTokens[1]),
						std::stoi(rectTokens[2]), std::stoi(rectTokens[3])));

				worldItems[std::stoi(id)] = obj;

				in >> x;
			}

		} while (x.compare("-.") != 0);

		std::string coll;
		in >> coll;
		std::vector<std::string> collv = split(coll, ',');

		std::unordered_set<int> collID;
		for (std::string id : collv)
		{
			collID.insert(std::stoi(id));
		}

		in.close();
		return World(
			sf::Vector2f(std::stof(worldPosTokens[0]), std::stof(worldPosTokens[1])),
			sf::IntRect(std::stoi(worldRectTokens[0]), std::stoi(worldRectTokens[1]),
				std::stoi(worldRectTokens[2]), std::stoi(worldRectTokens[3])),
			worldItems, collID);
	}

	////////////////////////////////////////////////////////////
	void SaveMachine::save_player(std::string path, Player player)
	{
		out.open(path);
		if (!out)
		{
			std::cout << "Unable to open file" << std::endl;
			exit(1);
		}
		out << player.get_writable();

		out.close();
	}

	////////////////////////////////////////////////////////////
	void SaveMachine::save_world(std::string path, World world)
	{
		out.open(path);
		if (!out)
		{
			std::cout << "Unable to open file" << std::endl;
			exit(1);
		}
		out << world.get_writeable();

		out.close();
	}

} // namespace rpg
