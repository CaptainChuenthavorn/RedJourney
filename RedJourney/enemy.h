#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "animationEnemy.h"
class enemy
{
public :
	enemy(sf::Texture* texture,sf::Vector2u imageCount, float switchTime, float speed);
	~enemy();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OncollisionEnemy(sf::Vector2f direction);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private: 
	sf::Clock cl;
	float enycl;
	sf::RectangleShape bound;
	sf::RectangleShape body;
	animationEnemy animationEnemy;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;
};

