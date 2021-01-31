#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	//Background
	sf::Texture backtexture;
	backtexture.loadFromFile("stars.png");
	sf::Sprite backsprite;
	backsprite.setTexture(backtexture);

	//Ship
	sf::Texture shiptexture;
	sf::Sprite shipsprite;
	shiptexture.loadFromFile("ship.png");
	shipsprite.setTexture(shiptexture);
	shipsprite.setScale(0.3, 0.3);
	shipsprite.setPosition(130, 450);

	//Enemy
	sf::Texture enemytexture;
	sf::Sprite enemysprite;
	enemytexture.loadFromFile("enemy.png");
	enemysprite.setTexture(enemytexture);
	enemysprite.setScale(0.1, 0.1);
	enemysprite.setPosition(130, 100);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//Draw
			window.draw(backsprite);
			window.draw(shipsprite);
			window.draw(enemysprite);
			window.display();

			//Movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
				shipsprite.move(4, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
				shipsprite.move(-4, 0);
		}
	}
	return 0;
}