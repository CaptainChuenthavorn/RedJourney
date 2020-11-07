#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed, float jumpHeight) :
	animation(texture,imageCount,switchTime)/* to get animation class*/
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0, 74.0));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(350.0f, 250.0f);
	body.setTexture(texture);

	//body.setFillColor(sf::Color::Red);

}
Player::~Player() {

}

void Player::Update(float deltaTime)
{
	//printf("%s\n", canJump ? "true" : "false");
	
	velocity.x *= 0.8f; // 0.2 slow 0.8 fast 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{ 
		row = 1;
		velocity.x -= speed;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		row = 1;
		velocity.x += speed;
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		row = 2;

		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		//square root (2.0f * gravity * jumpHeight)

	}
	
	velocity.y += 981.0f * deltaTime;
	if(velocity.x == 0.0f) 
	{
		row = 0;
		if (imageCount.x >= 3)
			imageCount.x = 0;
	}
	else {
		//row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity*deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	printf("direction y =%f", direction.y);
	printf("    %s\n", canJump ? "true" : "false");
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
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;
		//canJump = true;
	}
}
