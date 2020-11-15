#pragma once
#include <sfml/Graphics.hpp>
#include "Collider.h"

class Item
{
public:
	Item(sf::Texture* texture, sf::Vector2f position, sf::Vector2f velocity);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(position)) { body.setPosition(position); }

	void setSpawn(bool isSpawn);
	bool isSpawn() { return isSpawnBool; }
	void setDestroy(bool isDestroy);
	Collider GetCollider() { return Collider(body); }

	void OnCollision(sf::Vector2f direction);
	bool isDestroy() { return isDestroyBool; }

private:
	sf::RectangleShape body;
	sf::RectangleShape texture;


	sf::Vector2f velocity;

	bool isDestroyBool;
	bool isSpawnBool;

};

