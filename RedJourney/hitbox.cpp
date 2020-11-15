#include "hitbox.h"

hitbox::hitbox(float offset_x, float offset_y, sf::Vector2f size, sf::Vector2f playerposition)

{
	//hitboxplayer.setSize(sf::Vector2f(44.0f + 28.0f, 58.0f));
	hitboxplayer.setSize(size);
	hitboxplayer.setOrigin(hitboxplayer.getSize() / 2.0f);
	hitboxplayer.setPosition(playerposition.x + offset_x, playerposition.y + offset_y);

	hitboxplayer.setFillColor(sf::Color::Transparent);
	hitboxplayer.setOutlineThickness(2.f);
	hitboxplayer.setOutlineColor(sf::Color::Red);
}

void hitbox::Update(float offset_x, float offset_y, sf::Vector2f playerposition)
{
	hitboxplayer.setPosition(playerposition.x + offset_x, playerposition.y + offset_y);
}

void hitbox::Draw(sf::RenderWindow& window)
{
	window.draw(hitboxplayer);
}

const sf::Vector2f& hitbox::getPosition() const
{
	return this->hitboxplayer.getPosition();
}

const sf::FloatRect hitbox::getGlobalbounds() const
{
	return this->hitboxplayer.getGlobalBounds();
}

bool hitbox::intersects(const sf::FloatRect& frect)
{
	return this->hitboxplayer.getGlobalBounds().intersects(frect);
}