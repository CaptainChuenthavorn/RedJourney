#pragma once
#include <SFML\Graphics.hpp>
class animationEnemy
{
public: 
	animationEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~animationEnemy();
	void Update(int row, float deltaTime, bool faceRight);
	sf::IntRect uvRect;

public:
	
	//enemy movement
	bool idle = true;
	bool run = false;
	bool attack = false;
	bool dead = false;
	bool shieldBlocking = false;

	sf::Clock cl;
	float anicl;

	sf::Vector2u currentImage;
	sf::Vector2u imageCount;

	float totalTime;
	float switchTime;
private:

};

