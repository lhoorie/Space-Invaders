#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace std;

class Enemy {
private:
	sf::Texture enemytexture;
	sf::Sprite enemysprite;
	bool alive;
	
public:
	Enemy(int id) {
		alive = true;
		enemytexture.loadFromFile("enemy.png");
		enemysprite.setTexture(enemytexture);
		enemysprite.setScale(0.1, 0.1);
	}
	sf::Sprite getsprite() {
		return enemysprite;
	}
	bool isalive(){
		return alive;
	}
	void kill() {
		alive = false;
	}
	void setpocation(float x, float y)
	{
		enemysprite.setPosition(x, y);
	}

};
int main()
{
	bool gameover = false;
	bool win = false;

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

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Enemy
		for (int i = 0; i < 3; i++)
		{
			Enemy alien(i);
			alien.setpocation(i * 100 + 50, 100);
		}
		for (int i = 3; i < 6; i++)
		{
			Enemy alien(i);
			alien.setpocation(i * 100 + 50, 200);
		}

		//Draw
		window.draw(backsprite);
		window.draw(shipsprite);
		for (int i = 0; i < 6; i++)
			window.draw(alien(i).getsprite());
		window.display();

		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			shipsprite.move(4, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			shipsprite.move(-4, 0);
	}
	return 0;
}