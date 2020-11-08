#pragma once
#include <SFML\Graphics.hpp>
#include "animation.h"
#include "Collider.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed, float jumpHeight);
	~Player();
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& widow); // need to have a & to run in one window
	void OnCollision(sf::Vector2f direction);
	sf::Vector2f GetPosition() {return body.getPosition();}
	Collider GetCollider() { return Collider(body); }


private:
	sf::Clock aniCl;
	float animaCl;
	sf::RectangleShape bound;
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

};