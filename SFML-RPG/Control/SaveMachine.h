#pragma once
#include "..\WorldItems\World.h"
#include "..\Character\Player.h"

class SaveMachine
{
public:
	SaveMachine();
	void fullSave();
	void playerSave(Player player);


private:

	const char* playPath  = "playFile.txt";
	const char* worldPath = "worldFile.txt";

};