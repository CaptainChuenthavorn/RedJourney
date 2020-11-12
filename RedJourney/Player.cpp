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


	//bullet
	bullet.setSize(sf::Vector2f(20.0f, 10.0f));
	bullet.setFillColor(sf::Color::Black);
	bullet.setPosition(body.getPosition());
	

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
	if(animation.attack1==false)
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

	if (animation.finishJump == true)
	{
		animation.jump = false;
		animation.finishJump = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		

		animation.currentImage.y = 5;
		animation.run = false;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = true;
	
	}
	if (animation.finishAttack1 == true)
	{
		animation.attack1 = false;
		animation.finishAttack1 = false;
	}
	//printf("       attack : 1 %s\n", animation.attack1 ? "true" : "false");
	/*if (animation.attack1 = true)
	{
		
		printf("%f", aniCl.getElapsedTime().asSeconds());
		
		if (aniCl.getElapsedTime().asSeconds() <=0.6f)
		{
			animation.attack1 = true;
		}
		else if (aniCl.getElapsedTime().asSeconds() >= 0.6f) { aniCl.restart();  animation.attack1 = false;
		}
	}*/
	
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && attackState == 0)
		//{
		//	//attack
		//	attackState = 1;
		//	if (faceRight == false) // หันขวา
		//	{
		//		hitbox.setSize(sf::Vector2f(44.0f + 28.0f, 58.0f));
		//		hitbox.setPosition(body.getPosition().x - 28.0f, body.getPosition().y);
		//	}
		//	else if (faceRight == true)  // หันซ้าย
		//	{


		//		hitbox.setSize(sf::Vector2f(44.0f + 28.0f, 58.0f));


		//	}
		//	start = clock();
		//	animation.currentImage.y = 5;
		//	animation.run = false;
		//	animation.idle = false;
		//	animation.jump = false;
		//	animation.attack1 = true;
		//}
		//printf("time : %d  ", attackState);
		//printf("attack : %s\n", animation.attack1 ? "true" : "false");
		//printf("%lf\n", end - start);
		/*if (attackState > 0)
		{
			if (attackState == 1)
			{
				if (hitbox.getGlobalBounds().intersects(enemy1.getGlobalBounds()))
				{
					//printf("%s\n", hitbox.getGlobalBounds().intersects(enemy1.getGlobalBounds()) ? "true" : "false");
					attackState = 2;
					if (faceRight == true)
					{
						
						enemy1.move(20.0f, 0.f);
					}
					else if (faceRight == false)//หันขวา
					{
						enemy1.move(-20.0f, 0.f);

					}
					
				}
				}
				
				double dif = (double)(end - start) / CLOCKS_PER_SEC; // ความห่างของเวลา //0.6  0.4  0.4
				
				if (dif > 0.8f)//พร้อมตี พร้อมกด k อีกรอบ
				{
					animation.attack1 = false;
					attackState = 0;

				}
				else if (dif > 0.6f)//เข้าช่วงคูลดาว
				{
					animation.attack1 = true;
					attackState = 2;

				}

				else if (dif <= 0.6f)
				{
					animation.attack1 = true;
					
				}
			
		}*/
	

	//Bullet
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		bullet.setPosition(body.getPosition());
		shoot = 1;

		animation.currentImage.y = 5;
		
		animation.run = false;
		animation.idle = false;
		animation.jump = false;
		animation.attack1 = true;

	}
	if (shoot == 1)
		bullet.move(5.f, 0.0f);//spped x axis 20,y axis=0
	
	velocity.y += 981.0f * deltaTime;
	if(velocity.x == 0.0f) 
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
	body.move(velocity*deltaTime);
	hitbox.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	
	
	window.draw(bullet);
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
