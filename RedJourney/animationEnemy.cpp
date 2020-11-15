#include "C:\RedReborn\RedReborn\animationEnemy.h"

animationEnemy::animationEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;//at row Frame 
	uvRect.width = texture->getSize().x / float(imageCount.x);//widyth of sprite
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

animationEnemy::~animationEnemy()
{
}

void animationEnemy::Update(int row, float deltaTime, bool faceRight)
{
	if (idle == true)
	{
		currentImage.y = row;
		totalTime += deltaTime;

		if (totalTime >= switchTime) { // for smooth frame
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= 5) {
				currentImage.x = 0;
			}
		}

		uvRect.top = currentImage.y * uvRect.height;
		if (faceRight) {
			uvRect.left = currentImage.x * uvRect.width;
			uvRect.width = abs(uvRect.width);
		}
		else {
			uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
			uvRect.width = -abs(uvRect.width);
		}
	}

	if (run == true)
	{
		currentImage.y = row;
		totalTime += deltaTime;

		if (totalTime >= switchTime) { // for smooth frame
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
			}
		}

		uvRect.top = currentImage.y * uvRect.height;
		if (faceRight) {
			uvRect.left = currentImage.x * uvRect.width;
			uvRect.width = abs(uvRect.width);
		}
		else {
			uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
			uvRect.width = -abs(uvRect.width);
		}
	}
}
