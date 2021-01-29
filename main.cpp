#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	sf::Texture texture;
	texture.loadFromFile("stars.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders!");
	while (window.isOpen())
	{
		sf::Event event;
		class ship
		{
		private:
			sf::Texture texture;
		public:
			sf::Sprite sprite;
			texture.loadFromFile("ship.png");
			sprite.setTexture(texture);
			sprite.setScale(0.2, 0.2);
			sprite.setPosition(130, 500);
		};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			window.draw(sprite);
			window.draw(ship.sprite);
			window.display();
		}
	}
	return 0;
}