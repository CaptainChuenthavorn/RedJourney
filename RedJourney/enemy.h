#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "animationEnemy.h"
#include "Player.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
class enemy
{
public :
	
	enemy(sf::Texture* texture,sf::Vector2u imageCount, float switchTime, float speed,float PosX , float PosY);
	~enemy();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OncollisionEnemy(sf::Vector2f direction);
	sf::FloatRect GetGlobalbounds() { return body.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetSize() { return body.getSize(); }
	
	Collider GetCollider() { return Collider(body); }
	Collider GetColliderHitbox() { return Collider(hitbox); }
	sf::Vector2f SetPositionBounce(float move);

	void setHp(float dmg);
	float GetHp() { return hp; }
	float hp = 100;
	

	void render(sf::RenderTarget& target);
	

public: 
	sf::Clock cl;
	float enycl;
	sf::RectangleShape bound;
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	animationEnemy animationEnemy;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;
	

	
};

