#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720),"Red Adventure",sf::Style::Close|sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(288.0, 288.0));
	player.setPosition(280.0f, 150.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("WALK_RUN.PNG");
	player.setTexture(&playerTexture);
	animation Animation(&playerTexture, sf::Vector2u(6, 2),0.3f);
	float deltaTime=0.0f;
	sf::Clock clock;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt)) 
		{
			switch (evnt.type) 
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		
		Animation.Update(0,deltaTime);
		player.setTextureRect(Animation.uvRect);
		window.clear(sf::Color(150,150,150));
		window.draw(player);
		window.display();

	}
	return 0;

}
