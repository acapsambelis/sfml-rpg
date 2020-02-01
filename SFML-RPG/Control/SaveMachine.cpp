#include "SaveMachine.h"
#include <fstream>

SaveMachine::SaveMachine()
{
}

void SaveMachine::fullSave()
{

}

void SaveMachine::playerSave(Player player)
{
	std::ofstream playerFile;
	playerFile.open(playPath);
	playerFile << player;
}
