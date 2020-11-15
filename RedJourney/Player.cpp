#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)/* to get animation class*/

{
	//player
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0, 74.0));
	//body.setSize(sf::Vector2f(40.0, 29.6));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(350.0f, 250.0f);
	body.setTexture(texture);

	//hitbox
	hitboxAttack.setSize(sf::Vector2f(44.0f + 28.0f, 58.0f));
	hitboxAttackRight.setSize(sf::Vector2f(44.0f + 28.0f, 58.0f));
	hitboxSize.setSize(sf::Vector2f(44.0f, 58.0f));

	hitbox.setSize(hitboxSize.getSize());
	hitbox.setOrigin(hitbox.getSize() / 2.0f);
	hitbox.setPosition(body.getPosition());
	hitbox.setFillColor(sf::Color::Blue);





}
Player::~Player() {

}

void Player::Update(float deltaTime)
{

	end = clock();

	hitbox.setSize(hitboxSize.getSize());
	hitbox.setPosition(body.getPosition().x, body.getPosition().y);
	hitbox.setOrigin(hitbox.getSize() / 2.0f);
	//printf("%s\n", canJump ? "true" : "false");

	velocity.x *= 0.8f; // 0.2 slow 0.8 fast 
	if (animation.attack1 == false)
		animation.idle = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		row = 1;
		velocity.x -= speed;
		animation.run = true;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = false;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{


		row = 2;
		velocity.x += speed;
		animation.run = true;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = false;

	}

	//printf("%.2f\n", stamina);
	if (stamina > 50) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{

			stamina -= 1;
			row = 1;
			velocity.x -= speed + 0.1;
			animation.run = true;
			animation.idle = false;
			animation.jump = false;
			animation.attack1 = false;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{

			stamina -= 1;
			row = 2;
			velocity.x += speed + 0.1;
			animation.run = true;
			animation.idle = false;
			animation.jump = false;
			animation.attack1 = false;

		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (stamina <= maxstamina)
			stamina += 0.25;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		animation.currentImage.y = 2;
		animation.run = false;
		animation.idle = false;
		animation.attack1 = false;
		animation.jump = true;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		//Formula : square root (2.0f * gravity * jumpHeight)
	}

	/*if (animation.finishJump == true)
	{
		animation.jump = false;
		animation.finishJump = false;
	}*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{


		animation.currentImage.y = 5;
		animation.run = false;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = true;

	}
	//Bullet
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{


		animation.currentImage.y = 10;

		animation.run = false;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = false;
		animation.shoot = true;

	}

	if (animation.finishAttack1 == true)
	{
		animation.attack1 = false;
		animation.finishAttack1 = false;
	}

	if (animation.finishShoot == true)
	{
		animation.shoot = false;
		animation.finishShoot = false;
	}




	if (animation.hurt == true)
	{
		//animation.currentImage.y = 7;
		//velocity.x = 0.0f;
		animation.run = false;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = false;

	}

	immortalCl = imCl.getElapsedTime().asSeconds();
	//printf("Time %f  ", immortalCl);
	if (immortal == true && immortalCl > immortalTime)
	{
		if (animation.crashEnemy == true)
		{
			animation.hurt = false;
		}

		hpPlayer = currentHp;
		immortal = false;
		imCl.restart();

	}

	velocity.y += 981.0f * deltaTime;
	if (velocity.x == 0.0f)
	{
		row = 0; // idle
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
	body.move(velocity * deltaTime);
	hitbox.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(hitbox);
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	//printf("direction y =%f", direction.y);
	//printf("    %s\n", canJump ? "true" : "false");
	if (direction.x < 0.0f) {
		//collision on the left
		velocity.x = 0.0f;
		canJump = true;
	}
	else if (direction.x > 0.0f) {
		//collision on the right
		velocity.x = 0.0f;
		canJump = true;
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
