#include "Animation.h"

Animation::Animation(std::string texture, bool frozen, sf::Vector2u imageCount, float switchTime)
{
	this->frozen = frozen;
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	sf::Texture text;
	text.loadFromFile(texture.c_str());
	uvRect.width  = text.getSize().x / float(imageCount.x);
	uvRect.height = text.getSize().y / float(imageCount.y);

}


Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top  = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}


void Animation::setImageCount(sf::Vector2u imageCount)
{
	this->imageCount = imageCount;
}
void Animation::setSwitchTime(float switchTime)
{
	this->switchTime = switchTime;
}
