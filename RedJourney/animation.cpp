#include "C:\RedReborn\RedReborn\animation.h"


animation::animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;//at row Frame 
	uvRect.width = texture->getSize().x / float(imageCount.x);//widyth of sprite
	uvRect.height = texture->getSize().y / float(imageCount.y);
}
animation::~animation()
{

}

void animation::Update(int row, float deltaTime, bool faceRight)
{

	if (idle == true)
	{
		currentImage.y = 0;
		totalTime += deltaTime;
		if (totalTime >= switchTime) // for smooth frame
		{
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= 4) {
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

	else if (run == true)
	{
		currentImage.y = 1;
		totalTime += deltaTime;

		if (totalTime >= switchTime) // for smooth frame
		{
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= 6) {
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

	else if (jump == true)
	{

		totalTime += deltaTime;


		if (totalTime >= switchTime) // for smooth frame
		{
			//printf("%d    %d\n", currentImage.x, currentImage.y);
			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x >= 8) {

				currentImage.x = 0;
				//finishJump = true;
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

	else if (attack1 == true)
	{


		totalTime += deltaTime;

		if (totalTime >= switchTime) // for smooth frame
		{
			//printf("    %d\n", currentImage.x);

			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x >= 8) {
				currentImage.x = 2;
				//finishAttack1 = true;
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

	else if (shoot == true && finishShoot == false)
	{
		totalTime += deltaTime;

		if (totalTime >= switchTime) // for smooth frame
		{
			//printf("    %d\n", currentImage.x);

			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x >= 8) {
				currentImage.x = 2;
				finishShoot = true;
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


	else if (hurt == true)
	{

		// 3 7
		currentImage.y = 7;

		totalTime += deltaTime;

		if (totalTime >= switchTime) // for smooth frame
		{
			//printf("    %d\n", currentImage.x);

			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x >= 6) {
				currentImage.x = 3;

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
	/*
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
	}*/
}

