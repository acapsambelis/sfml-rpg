#pragma once
#include <SFML\Graphics.hpp>
#include <fstream>

class Animation
{
public:
	Animation(const char* texture, bool frozen, sf::Vector2u imageCount, float switchTime);
	~Animation();

	friend std::ostream& operator<<(std::ostream& os, const Animation& an);

public:
	sf::IntRect uvRect;
	bool frozen;

	void Update(int row, float deltaTime, bool faceRight);

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};
