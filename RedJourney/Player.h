#pragma once
#include <SFML\Graphics.hpp>
#include "animation.h"
#include "Collider.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	~Player();
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& widow);
	sf::Vector2f GetPosition() {return body.getPosition();}
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};