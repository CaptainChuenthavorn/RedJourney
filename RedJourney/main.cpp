#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
static const float VIEW_HEIGHT = 720.0f;

static const float VIEW_WIDTH = 1080.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Red Adventure", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
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
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}
	Player.Update(deltaTime);
	view.setCenter(Player.GetPosition()); // must follow Update
	window.clear(sf::Color(150, 200, 200));
	window.setView(view);
	Player.Draw(window);
	window.display();
	}
	return 0;
}

