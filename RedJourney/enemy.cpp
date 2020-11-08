#include "enemy.h"

enemy::enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
	:animationEnemy(texture, imageCount, switchTime)
{
	this->speed = speed;
	
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(128.0, 128.0));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(600.0f, 600.0f);
	body.setTexture(texture);
	
}

enemy::~enemy()
{
}

void enemy::Update(float deltaTime)
{
	animationEnemy.idle = true;
	velocity.x *= 0.8f; // 0.2 slow 0.8 fast 
	velocity.y += 981.0f * deltaTime;
	//velocity.x += speed;
	enycl = cl.getElapsedTime().asSeconds();
	printf("%f\n", enycl);
	if (enycl >= 0)
	{
		velocity.x -= speed;	
	}
	if (enycl >= 2)
	{
		velocity.x += speed;
		cl.restart();
	}
	
	if (velocity.x == 0.0f)
	{
		row = 0; // idle
		if (imageCount.x >= 5)
			imageCount.x = 0;
	}
	else {
		row = 1;
		if (velocity.x > 0.0f) 
			faceRight = true;
		else
			faceRight = false;//หันหน้าไปทางซ้าย
	}
	animationEnemy.Update(row, deltaTime, faceRight);
	body.setTextureRect(animationEnemy.uvRect);
	body.move(velocity * deltaTime);
}

void enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void enemy::OncollisionEnemy(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f) {
		//collision on the right
		velocity.x = 0.0f;
		
	}
	if (direction.y <= 0.0f) {
		//collision on the bottom

		velocity.y = 0.0f;
		
	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;
		
	}
}