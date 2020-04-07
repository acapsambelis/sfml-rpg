#include "Game.h"
#include <unordered_set>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run(float deltaTime, Player& player, World& world)
{
	player.Update(deltaTime);
	Collide(player, world);
}


void Game::Collide(Player& player, World& world)
{
	std::unordered_set<int> eraseIDs;
	for (auto id : world.collID)
	{
		bool mined = player.Collide(world.worldItems[id]);
		if (mined)
		{
			eraseIDs.insert(id);
		}
	}
	for (int id : eraseIDs)
	{
		world.worldItems.erase(id);
		world.collID.erase(id);
	}

}
