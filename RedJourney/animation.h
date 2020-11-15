#pragma once
#include <SFML\Graphics.hpp>
//enum Player_Animate_State { idle = 0, run, fall, idleWithSword, attack1, attack2, attack3, hurt, drawSword, keepSword, jump };

class animation
{
public://  import texture to get size  /No. of row and column/ how long we want each part take
	animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
	~animation();
	/*    update row      for fps stable    */
	void Update(int row, float deltaTime, bool faceRight);

public:
	clock_t end, start;

	
	
	sf::IntRect uvRect;

	//run, fall, idleWithSword, attack1, attack2, attack3, hurt, drawSword, keepSword, jump
	bool idle = true;
	bool run = false;
	bool jump = false;
	bool shoot = false;
	bool finishShoot = false;
	bool attack1 = false;
	bool attack2 = false;
	bool attack3 = false;
	bool hurt = false;
	bool drawSword = false;
	bool keepSword = false;
	bool canAttack = true;
	bool finishAttack1 = false;
	bool finishJump = false;
	bool crashEnemy = false;
	//enemy
	bool enemyWalk = true;
	sf::Clock cl;
	float anicl;

	sf::Vector2u currentImage;
	sf::Vector2u imageCount;

	float totalTime;
	float switchTime;
private:
	

	

};
