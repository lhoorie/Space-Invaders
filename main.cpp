#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace std;

class Bullet {
private:
	sf::Sprite bulletsprite;
	sf::Texture bullettexture;
	bool alive;
public:
	Bullet(int i, float speed) {
		alive = false;
		bullettexture.loadFromFile("bullet.png");
		bulletsprite.setTexture(bullettexture);
		bulletsprite.setScale(0.05, 0.05);
	}
	void setlocation(float x, float y)
	{
		bulletsprite.setPosition(x, y);
	}
	sf::Sprite getsprite()
	{
		return bulletsprite;
	}
	void kill()
	{
		alive = false;
	}

	bool isalive()
	{
		return alive;
	}
	void idk(bool tf) {
		alive = tf;
	}
};

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
	void setlocation(float x, float y)
	{
		enemysprite.setPosition(x, y);
	}

};

class Ship {
private:
	sf::Texture shiptexture;
	sf::Sprite shipsprite;
	bool alive;
public:
	Ship(){
		alive = true;
		shiptexture.loadFromFile("ship.png");
		shipsprite.setTexture(shiptexture);
		shipsprite.setScale(0.3, 0.3);
	}
	void setlocation(float x, float y)
	{
		shipsprite.setPosition(x, y);
	}

	sf::Sprite getsprite()
	{
		return shipsprite;
	}

	void kill()
	{
		alive = false;
	}

	bool isalive()
	{
		return alive;
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

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Ship
		Ship ship;

		//Bullet
		Bullet bullet(0, 10);


		//Enemy
		for (int i = 0; i < 3; i++)
		{
			Enemy alien(i);
			alien.setlocation(i * 100 + 50, 100);
		}
		for (int i = 3; i < 6; i++)
		{
			Enemy alien(i);
			alien.setlocation(i * 100 + 50, 200);
		}

		//Draw
		window.draw(backsprite);
		window.draw(ship.getsprite());
		for (int i = 0; i < 6; i++)
			window.draw(alien(i).getsprite());
		window.display();

		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			ship.getsprite().move(4, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			ship.getsprite().move(-4, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			bullet.idk(true);
			bullet.setlocation(ship.getsprite().getPosition().x + 31, ship.getsprite().getPosition().y - 15);
		}
	}
	return 0;
}