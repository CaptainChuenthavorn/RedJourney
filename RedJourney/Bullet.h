#pragma once
#include <sfml/Graphics.hpp>
#include "animation.h"
#include "Collider.h"

class Bullet
{
public:
	Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position,sf::Vector2f velocity);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(position)) { body.setPosition(position); }

	void setDestroy(bool isDestroy);
	Collider GetCollider() { return Collider(body); }
	bool isDestroy() { return isDestroyBool; }

	float GetDmg() { return dmg; }
private:
	sf::RectangleShape body;
	sf::RectangleShape texture;
	animation animation;
	unsigned int row;
	sf::Vector2f velocity;

	bool isDestroyBool;
	float speed;
	int dmg;
};

