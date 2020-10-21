#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
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

	Player player(&playerTexture, sf::Vector2u(6, 2), 0.3f, 100.0f,200.0f);
	
	std::vector<Platform> platforms;
	//Ground
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.f), sf::Vector2f(500.0f, 500.0f));
	float deltaTime = 0.0f;
	
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
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
	player.Update(deltaTime);
	sf::Vector2f direction;
	
	/*for (int i = 0; i < platforms.size();i++) {
		Platform& platform = platforms[i];
	}	equal to this below command*/
//	Collider playerCollision = player.GetCollider();
	for (Platform& platform : platforms)// == for(int i =0 ; i<platforms.size();i++)
		if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			player.OnCollision(direction);
	//Collider playerCollision = player.GetCollider();

	/*
	platform1.GetCollider().CheckCollision(playerCollision, 0.0f);

	platform2.GetCollider().CheckCollision(playerCollision, 1.0f);*/
	view.setCenter(player.GetPosition()); // must follow Update
	window.clear(sf::Color(150, 200, 200));
	window.setView(view);
	player.Draw(window);
	/*platform1.Draw(window);
	platform2.Draw(window);*/
	for (Platform& platform : platforms)
		platform.Draw(window);
	window.display();
	}
	return 0;
}