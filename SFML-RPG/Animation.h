#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, bool frozen, sf::Vector2u imageCount, float switchTime);
	~Animation();

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
