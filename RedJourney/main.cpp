#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720),"Red Adventure",sf::Style::Close|sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(288.0, 288.0));
	player.setPosition(280.0f, 150.0f);
	//player.setFillColor(sf::Color::Red);
	sf::Texture playerTexture;
	//playerTexture.loadFromFile("MG.jpg");
	
	//playerTexture.loadFromFile("Woodcutter_walk.PNG");
	playerTexture.loadFromFile("WALK_RUN.PNG");
	player.setTexture(&playerTexture);
	animation Animation(&playerTexture, sf::Vector2u(6, 2),0.3f);
	sf::Vector2u textureSize = playerTexture.getSize();
	/*textureSize.x /= 6;
	//textureSize.y /= 2;
	player.setTextureRect(sf::IntRect(textureSize.x*0, textureSize.y*0, textureSize.x, textureSize.y));
	*/
	//player.setOrigin(50.0f, 50.0f);
	float deltaTime=0.0f;
	sf::Clock clock;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//std::cout << "New window width : " << evnt.size.width << " New window height : " << evnt.size.height << std::endl;
				printf("New window width : %i New window height : %d\n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}
			}
			/*if (evnt.type == evnt.Closed) {
				window.close();
			}*/
		}
		/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.1f);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
		}*/
		Animation.Update(0,deltaTime);
		player.setTextureRect(Animation.uvRect);
		window.clear(sf::Color(150,150,150));
		window.draw(player);
		window.display();

	}
	return 0;

}
