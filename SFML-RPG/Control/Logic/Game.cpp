#include "Game.h"

Game::Game()
{
	this->deltaTime = 0.0f;
}

Game::~Game()
{
}

void Game::Run(Player& player, World& world)
{
	this->deltaTime = this->clock.restart().asSeconds();
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
