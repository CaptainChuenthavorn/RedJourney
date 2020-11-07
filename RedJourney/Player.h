#pragma once
#include <SFML\Graphics.hpp>
#include "animation.h"
#include "Collider.h"
enum Player_Animate_State { idle=0, run, fall, idleWithSword, attack1, attack2, attack3, hurt, drawSword, keepSword, jump };
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
	sf::RectangleShape bound;
	sf::RectangleShape body;
	animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

};