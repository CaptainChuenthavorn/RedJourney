#include "Boss.h"

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float PosX, float PosY)
	:animationEnemy(texture, imageCount, switchTime)
{
	this->isDieBool = false;
	this->isDieSpawnBool = false;
	this->speed = speed;
	this->hp = 10;

	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(128.0, 128.0));//Old

	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(PosX, PosY);
	body.setTexture(texture);
	body.setScale(2.0f, 2.0f);


	hitbox.setSize(sf::Vector2f(60.0, 50.0));
	//hitbox.setSize(sf::Vector2f(42.0, 57.6));
	hitbox.setOrigin(hitbox.getSize() / 2.0f);
	hitbox.setPosition(body.getPosition().x, body.getPosition().y);
	hitbox.setFillColor(sf::Color::Yellow);
}

Boss::~Boss()
{
}

void Boss::Update(float deltaTime)
{
	srand(time(NULL));

	hitbox.setPosition(body.getPosition().x, body.getPosition().y);
	animationEnemy.idle = true;
	velocity.x *= 0.8f; // 0.2 slow 0.8 fast 
	velocity.y += 981.0f * deltaTime;
	//velocity.x += speed;
	enycl = cl.getElapsedTime().asSeconds();
	//3 6 9
	if (enycl <= 3.0f)
	{
		velocity.x += speed * 0.7;

	}
	else if (enycl <= 6.0f && enycl >= 3.0f)
	{
		velocity.x = 0;

	}
	else if (enycl <= 9.0f && enycl >= 6.0f)
	{
		velocity.x -= speed * 0.7;
		enycl = 0.0f;
	}
	else {

		cl.restart();
	}

	if (velocity.x == 0.0f)
	{
		row = 0; // idle
		if (imageCount.x >= 5)
			imageCount.x = 0;
	}
	else {
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;//หันหน้าไปทางซ้าย
	}
	animationEnemy.Update(row, deltaTime, faceRight);
	body.setTextureRect(animationEnemy.uvRect);
	body.move(velocity * deltaTime);//Before : velocity * deltaTime
}

void Boss::Draw(sf::RenderWindow& window)
{
	window.draw(hitbox);
	window.draw(body);
}

void Boss::OncollisionEnemy(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//collision on the left
		velocity.x = -velocity.x;
		velocity.x = 0.0f;

	}
	else if (direction.x > 0.0f) {
		//collision on the right
		velocity.x = -velocity.x;
		velocity.x = 0.0f;

	}
	if (direction.y <= 0.0f) {
		//collision on the bottom

		velocity.y = 0.0f;

	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;

	}
}

sf::Vector2f Boss::SetPosition(sf::Vector2f randPos)
{
	body.setPosition(randPos);
	return body.getPosition();
}

void Boss::setHp(int dmg)
{
	this->hp -= dmg;
}

void Boss::setDie(bool isDie)
{
	this->isDieBool = isDie;

}

void Boss::setDieSpawn(bool isDieSpawn)
{
	this->isDieSpawnBool = isDieSpawn;
}