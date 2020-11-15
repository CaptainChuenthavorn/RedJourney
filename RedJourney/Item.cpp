#include "Item.h"


Item::Item(sf::Texture* texture, sf::Vector2f position, sf::Vector2f velocity)

{
	body.setSize(sf::Vector2f(40.f, 28.f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);

	this->isDestroyBool = false;
	this->velocity = velocity;
	this->isSpawnBool = false;
}

void Item::Update(float deltaTime)
{
	velocity.y += 981.0f * deltaTime;

	body.move(velocity * deltaTime);

}

void Item::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Item::setSpawn(bool isSpawn)
{
	this->isSpawnBool = isSpawn;
}

void Item::setDestroy(bool isDestroy)
{
	this->isDestroyBool = isDestroy;
}


void Item::OnCollision(sf::Vector2f direction)
{
	//printf("direction y =%f", direction.y);
	//printf("    %s\n", canJump ? "true" : "false");
	if (direction.x < 0.0f) {
		//collision on the left
		velocity.x = 0.0f;

	}
	else if (direction.x > 0.0f) {
		//collision on the right
		velocity.x = 0.0f;

	}
	if (direction.y <= 0.0f) {
		//collision on the bottom

		velocity.y = 0.0f;

	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;
		//canJump = true;
	}
}
