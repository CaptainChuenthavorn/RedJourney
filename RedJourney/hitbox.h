#pragma once
#include"player.h"

class hitbox
{
public:
	sf::RectangleShape hitboxplayer;
	hitbox(float offset_x, float offset_y, sf::Vector2f size, sf::Vector2f playerposition);

	void Update(float offset_x, float offset_y, sf::Vector2f playerposition);
	void Draw(sf::RenderWindow& window);
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalbounds() const;
	bool intersects(const sf::FloatRect& frect);

};