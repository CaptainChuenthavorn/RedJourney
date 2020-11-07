#pragma once
#include <SFML\Graphics.hpp>
class animation
{
public://  import texture to get size  /No. of row and column/ how long we want each part take
	animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
	~animation();
	/*    update row      for fps stable    */
	void Update(int row, float deltaTime, bool faceRight);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;
};
