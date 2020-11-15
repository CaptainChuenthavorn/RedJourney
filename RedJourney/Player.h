#pragma once
#include <SFML\Graphics.hpp>
#include "animation.h"
#include "Collider.h"
#include "enemy.h"
#include "animationEnemy.h"
#include "Bullet.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed, float jumpHeight);
	~Player();
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& widow); // need to have a & to run in one window
	void OnCollision(sf::Vector2f direction);
	sf::Vector2f GetPosition() {return body.getPosition();}
	sf::Vector2f GetSize() { return body.getSize(); }
	sf::Vector2f GetOrigin() { return body.getOrigin(); }
	Collider GetCollider() { return Collider(body); }
	Collider GetColliderHitbox() { return Collider(hitbox); }
	sf::RectangleShape hitbox;
	int hpPlayer = 3;
	sf::RectangleShape bullet;
	
	sf::RectangleShape enemy1;
public:
	int attackState=2;//0=Ready , 1=attacking , 2=cooldown
	int shootState = 2;//0=Ready , 1=attacking , 2=cooldown
	int jumpAni = 2;//0=Ready , 1 =jumping , 2=cooldown
	clock_t end, start;
	bool shoot = 0; //0=off,1=on
	sf::Clock aniCl;
	float animaCl;
	sf::RectangleShape bound;
	sf::RectangleShape body;
	sf::RectangleShape attack;
	
	float maxstamina = 1500;
	float stamina = 1500;
	

	sf::Clock imCl;
	float immortalCl;
	bool immortal = false;
	float immortalTime;
	int currentHp;

	animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	
	sf::RectangleShape hitboxAttackRight;
	sf::RectangleShape hitboxAttack;
	sf::RectangleShape hitboxSize;

	

};