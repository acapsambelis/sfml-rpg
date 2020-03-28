#pragma once
#include <SFML\Graphics.hpp>
#include <fstream>

class Animation
{
public:
	Animation(std::string texture, bool frozen, sf::Vector2u imageCount, float switchTime);
	~Animation();


	void Update(int row, float deltaTime, bool faceRight);

	void setImageCount(sf::Vector2u imageCount);
	void setSwitchTime(float switchTime);

public:
	sf::IntRect uvRect;
	bool frozen;


private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};
