#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "animationEnemy.h"
#include "Player.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
class Boss
{
public:

	Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float PosX, float PosY);
	~Boss();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OncollisionEnemy(sf::Vector2f direction);
	sf::FloatRect GetGlobalbounds() { return body.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetSize() { return body.getSize(); }
	sf::Vector2f SetPosition(sf::Vector2f randPos);
	Collider GetCollider() { return Collider(body); }
	Collider GetColliderHitbox() { return Collider(hitbox); }


	void setHp(int dmg);
	int GetHp() { return hp; }
	int hp;


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

	sf::Clock clockdead;

	void setDie(bool isDestroy);
	bool isDie() { return isDieBool; }
	bool isDieBool;

	//for not spawn enemy again
	void setDieSpawn(bool isDestroySpawn);
	bool isDieSpawn() { return isDieSpawnBool; }
	bool isDieSpawnBool;


};

