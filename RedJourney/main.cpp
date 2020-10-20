#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("WALK_RUN.PNG");


	Player Player(&playerTexture, sf::Vector2u(6, 2), 0.3f, 100.0f);
	float deltaTime = 0.0f;
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

	
	Player.Update(deltaTime);

	window.clear(sf::Color(150, 200, 200));
	Player.Draw(window);
	window.display();
	}
	return 0;
}

