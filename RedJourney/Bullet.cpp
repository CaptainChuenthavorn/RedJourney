#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, sf::Vector2f velocity) :
	animation(texture, imageCount, switchTime)/* to get animation class*/
{
	body.setSize(sf::Vector2f(100.f, 10.f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	this->dmg = 1;
	this->speed = speed;
	this->isDestroyBool = false;
	this->velocity = velocity;
}

void Bullet::Update(float deltaTime)
{
	//velocity.x = 500.0f; // speed of bullet //
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Bullet::setDestroy(bool isDestroy)
{
	this->isDestroyBool = isDestroy;
}
