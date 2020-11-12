#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Background.h"
#include "Player.h"
#include "Platform.h"
#include "enemy.h"
#include "hitbox.h" 
#include "Bullet.h"
sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
std::vector<enemy> enemies;
sf::Texture enemyBlack;
sf::Texture enemyGrey;
sf::Texture enemyGolden;
int spawnTime;
int spawnCooldown;
int enemyCount;
int enemyMax;
static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_WIDTH = 1080.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
void InitEnemy();
void renderEnemies();

int main()
{
	//bullet//
	std::vector<Bullet> bullet;
	sf::Texture bullet_texture;
	sf::Clock bullTime;
	float bull = 0.0f; //เป็นตัวเก็บค่า เวลาของ bullet
	//////////
	sf::RectangleShape bound;
	bound.setSize(sf::Vector2f(100.0, 74.0));
	bound.setOrigin(bound.getSize() / 2.0f);
	bound.setPosition(350.0f, 250.0f);
	bound.setFillColor(sf::Color::Red);

	sf::RectangleShape boundE;
	boundE.setSize(sf::Vector2f(100.0, 74.0));
	boundE.setOrigin(boundE.getSize() / 2.0f);
	boundE.setPosition(350.0f, 250.0f);
	boundE.setFillColor(sf::Color::Green);

	sf::Texture bgTexture[4];
	bgTexture[0].loadFromFile("asset/CloudsBack.png");
	bgTexture[1].loadFromFile("asset/CloudsFront.png");
	bgTexture[2].loadFromFile("asset/BGBack.png");
	bgTexture[3].loadFromFile("asset/BGFront.png");
	
	std::vector<Background> backgrounds;
	backgrounds.push_back(Background(&bgTexture[0], -5.f));
	backgrounds.push_back(Background(&bgTexture[1], -10.f));
	backgrounds.push_back(Background(&bgTexture[2], -15.f));
	backgrounds.push_back(Background(&bgTexture[3], -20.f));
	
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
	
	sf::Texture playerTexture;
	//playerTexture.loadFromFile("asset/Adventurer/Individual Sprites/adventurer-idle-00.PNG");
	playerTexture.loadFromFile("asset/v2.1/adventurer-1.3-Sheet.PNG");
	//playerTexture.loadFromFile("WALK_RUN_RedStroke.PNG");
	Player player(&playerTexture, sf::Vector2u(8,12), 0.1f, 100.0f,100.0f);
	
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("asset/16x16 knight 4 v3.PNG");
	enemy enemy(&enemyTexture, sf::Vector2u(8,8), 0.2f, 100.0f,500.0f,500.0f);


	//load enemy texture//
	enemyBlack.loadFromFile("asset/enemy/black.PNG");//16x16 knight 3 v3
	
	enemyGolden.loadFromFile("asset/enemy/16x16 knight 1 v3.PNG");
	
	enemyGrey.loadFromFile("asset/enemy/16x16 knight 2 v3.PNG");

	//initialize platform
	std::vector<Platform> platforms;
	//Ground && platform
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(1000.0f, 400.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(800.0f, 525.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 200.0f), sf::Vector2f(100.0f, 625.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 1000.0f), sf::Vector2f(-100.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 150.0f), sf::Vector2f(50.0f, 300.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 50.0f), sf::Vector2f(1500.0f, 575.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 75.0f), sf::Vector2f(1400.0f, 375.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 200.0f), sf::Vector2f(500.0f,775.0f)));
	

	//hitbox//  sf::Vector2f(44.0f + 28.0f, 58.0f)
	hitbox
		hitboxMid(0, 0, sf::Vector2f(22, player.GetSize().y), player.GetPosition());
	hitbox
		hitboxLeft(-28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());
	hitbox
		hitboxRight(+28, 0, sf::Vector2f(28, player.GetSize().y), player.GetPosition());
	
	hitbox
		hitboxEnemy(0, 0, sf::Vector2f(30, 48), enemy.GetPosition());

	//attack
	int cooldown = 0;

	//enemy.GetSize().y = 48


	float deltaTime = 0.0f;
	sf::Clock clockW;


	InitEnemy();
	while (window.isOpen()) {
		deltaTime = clockW.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
			
				break;
			
			}
		}

		//bullet update //
		bull = bullTime.getElapsedTime().asMilliseconds();
		if(bull > 800)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				bullet.push_back(Bullet(&bullet_texture, sf::Vector2u(), 0/*imageCOunt*/, sf::Vector2f(player.GetPosition().x + 10/* +10 เพื่อให้ออกทางขวาของตัวผู้เล่น*/, player.GetPosition().y)));
				bullTime.restart();
				/*
				player.attackState = 1;
				player.velocity.x = 0;
				//player.animation.attack1 = true;
				player.start = clock();
				*/
			}
		}
		/////////////////

		
	
		//player && enemy Update && hitboxupdate//
		sf::Vector2f direction;
		player.Update(deltaTime);
		enemy.Update(deltaTime);
		hitboxMid.Update(0, 0, player.GetPosition());
		hitboxLeft.Update(-28, 0, player.GetPosition());
		hitboxRight.Update(+28, 0, player.GetPosition());
		hitboxEnemy.Update(0, 0, enemy.GetPosition());

		for (Bullet& bullet : bullet){
			bullet.Update(deltaTime);
		}
		Collider temp = enemy.GetColliderHitbox();
		for (Bullet& bullet : bullet)
		{
			if (bullet.GetCollider().CheckCollision(temp,direction,1.0f)) {
				bullet.setDestroy(true);
				enemy.setHp(bullet.GetDmg());
			
			}
		}
		for (int b = 0;b < bullet.size();b++)
		{
			if (bullet[b].isDestroy())
			{
				bullet.erase(bullet.begin() + b);
			}
		}

		
		//player collider with platform//
		
		for (Platform& platform : platforms)// == for(int i =0 ; i<platforms.size();i++)
		if ( platform.GetCollider().CheckCollision ( player.GetCollider(), direction, 1.0f )  ) 
			player.OnCollision(direction);
		
		//enemy collider with platform
		for (Platform& platform : platforms)
		if (platform.GetCollider().CheckCollision(enemy.GetCollider(), direction, 1.0f))
			enemy.OncollisionEnemy(direction);

		//enemy.GetCollider().CheckCollision(player.GetCollider(),direction, 0.0f);//1 can slide ,0 can't do anything
		//	enemy.OncollisionEnemy(direction);

		if (enemy.GetColliderHitbox().CheckCollision(player.GetColliderHitbox(), direction, 1.0f))//1 can slide ,0 can't do anything
		{
			//printf("Collision! \n");
			
			enemy.OncollisionEnemy(direction);
			player.velocity.x = 0.0f;
			enemy.velocity.x = 0.0f;
			
		}
		
		//attack method
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && player.attackState == 0)
		{
			player.attackState = 1;
			player.velocity.x = 0;
			//player.animation.attack1 = true;
			player.start = clock();
			
		}
		
		//printf("attack : 1 %s\n",player.animation.attack1 ? "true" : "false");
		//printf("Attack state : %d\n", player.attackState);
		
		//attack//
		
		if (player.attackState > 0)
		{

			
			if (player.attackState == 1)
			{
				if (hitboxMid.getGlobalbounds().intersects(enemy.GetGlobalbounds()))
				{
					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
					{
						
						cooldown++;
						if (cooldown == 1 || cooldown == 2 || cooldown == 3)
						{
							//player.attackState = 1;
							player.velocity.x = 0;
							player.attackState = 2;
							//std::cout << "Hit" << std::endl;

							enemy.hp--;
							printf(" Hit enemy hp :%d    \n", enemy.hp);

							if (enemy.hp <= 0)
							{
								//std::cout << "Score " << std::endl;
							}
						}
					}
					/*if (player.faceRight = true)
					{
						enemy.SetPositionBounce(20.0f);

					}
					else if (player.faceRight == false)
					{
						enemy.SetPositionBounce(-50.f);

					}*/
				}
			}
			double dif = (double)(player.end - player.start) / CLOCKS_PER_SEC; // ความห่างของเวลา //0.6  0.4  0.4
			
			if (dif > 0.6f)//พร้อมตี พร้อมกด k อีกรอบ
			{
				cooldown = 0;
				player.attackState = 0;

			}
			else if (dif > 0.4f)//เข้าช่วงคูลดาว
			{
				player.animation.attack1 = false;
				player.attackState = 2;

			}

			else if (dif <= 0.4f)
			{
				//printf("%lf    ", dif);
				
				// std::cout << "Cooldown" << std::endl;
			}
			
		}



		//setview (must follow Update)//
		view.setCenter(player.GetPosition());  

		//set background slide//
		for (Background& background : backgrounds)
			background.Update(deltaTime);

		window.clear(sf::Color(150, 200, 200));
		
		//bound around player && enemy//
		bound.setPosition(player.GetPosition ().x, player.GetPosition().y);
		boundE.setPosition(enemy.GetPosition().x, enemy.GetPosition().y);
		
		//Draw bg//
		for (Background& background : backgrounds)
			background.Draw(window);

		//set view//
		window.setView(view);

		//draw  everything//
		hitboxEnemy.Draw(window);
		hitboxMid.Draw(window);
		hitboxLeft.Draw(window);
		hitboxRight.Draw(window);
		
		
		
		//draw Enemy vector
		

		renderEnemies();
		

		for (int i = 0;i < enemies.size();i++)
		{
			if (hitboxLeft.getGlobalbounds().intersects(enemies[i].GetGlobalbounds()))
			{

			}
		}
		if (enemy.hp <= 0) {
			for (int i = 0;i < enemies.size();i++)
			{
				enemies.erase(enemies.begin() + i);
			}
		}
		
		
		

		//window.draw(bound);
		//window.draw(boundE);
		player.Draw(window);
		if (enemy.hp > 0) {
			enemy.Draw(window);
		}
		//draw platforms//
		for (Platform& platform : platforms)
		platform.Draw(window);
		//draw bullet//
		for (Bullet& bullet : bullet)
			bullet.Draw(window);

		//display//
		window.display();
	 }
	return 0;
}


void InitEnemy()
{
	if (spawnTime == spawnCooldown && enemyCount < enemyMax || enemyCount < 3)
	{
		
		enemies.push_back(enemy(&enemyGolden, sf::Vector2u(8, 8), 0.2f, 100.0f,1000.0f,600.0f));
		enemies.push_back(enemy(&enemyGolden, sf::Vector2u(8, 8), 0.2f, 100.0f, 900.0f, 500.0f));
		enemies.push_back(enemy(&enemyGolden, sf::Vector2u(8, 8), 0.2f, 100.0f, 800.0f, 400.0f));
		enemies.push_back(enemy(&enemyGrey, sf::Vector2u(8, 8), 0.2f, 100.0f, 700.0f, 300.0f));
		enemies.push_back(enemy(&enemyGrey, sf::Vector2u(8, 8), 0.2f, 100.0f, 600.0f, 800.0f));
		for (int k = 0;k < enemies.size();k++)
		{
			hitbox
				hitboxEnemies(0, 0, sf::Vector2f(30, 48), enemies[k].GetPosition());
		}
		
		enemyCount++;
		std::cout << enemyCount << std::endl;
	}

}

void renderEnemies()
{

	for (int i = 0;i < enemies.size();i++)
	{
		enemies[i].render(window);
		
	}

}