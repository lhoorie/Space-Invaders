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
	Bullet() {
		alive = false;
		bullettexture.loadFromFile("bullet.png");
		bulletsprite.setTexture(bullettexture);
		bulletsprite.setScale(0.35, 0.35);
	}
	void setlocation(float x, float y){
		bulletsprite.setPosition(x, y);
	}
	void movedown() {
		bulletsprite.move(0, 1);
	}
	void moveup() {
		bulletsprite.move(0, -1);
	}
	sf::Sprite getsprite(){
		return bulletsprite;
	}
	void draw(sf::RenderWindow& win) {
		win.draw(bulletsprite);
	}
	void kill(){
		alive = false;
	}
	bool getalive(){
		return alive;
	}
	void isalive(bool tf) {
		alive = tf;
	}
};

class Enemy {
private:
	sf::Texture enemytexture;
	sf::Sprite enemysprite;
	bool alive;
public:
	Enemy(int x, int y) {
		alive = true;
		enemytexture.loadFromFile("enemy.png");
		enemysprite.setTexture(enemytexture);
		enemysprite.setPosition(x, y);
		enemysprite.setScale(0.6,0.6);
	}

	void leftright(int min,int max) {
		bool Arrow;
		if (enemysprite.getPosition().x >=max-60) {
			Arrow = false;
		}
		if (enemysprite.getPosition().x <= min) {
			Arrow = true;
		}

		if (Arrow) {
			enemysprite.move(0.25, 0);
		}
		else {
			enemysprite.move(-0.25, 0);
		}
	}
	sf::Sprite getsprite() {
		return enemysprite;
	}
	bool isalive() {
		return alive;
	}
	void kill() {
		alive = false;
	}
	void setlocation(float x, float y) {
		enemysprite.setPosition(x, y);
	}
	void draw(sf::RenderWindow& win) {
		win.draw(enemysprite);
	}

};

class Ship {
private:
	sf::Texture shiptexture;
	sf::Sprite shipsprite;
	int x;
	int y;
	bool alive;
public:
	Ship() {
		alive = true;
		shiptexture.loadFromFile("ship.png");
		shipsprite.setTexture(shiptexture);
		shipsprite.setScale(0.17, 0.17);
	}
	void setlocation(float x, float y) {
		shipsprite.setPosition(x, y);
	}

	void move()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			if (shipsprite.getPosition().x <=713) {
				shipsprite.move(1, 0);	
			}
		}
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			if (shipsprite.getPosition().x > 0) {
				shipsprite.move(-1, 0);
			}
		}
		x = shipsprite.getPosition().x;
	}
	sf::Sprite getsprite() {
		return shipsprite;
	}
	void kill() {
		alive = false;
	}
	bool isalive() {
		return alive;
	}
};

int main()
{
	bool gameover = false;
	bool win = false;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders!");

	//Background
	sf::Texture backtexture;
	backtexture.loadFromFile("stars.png");
	sf::Sprite backsprite;
	backsprite.setTexture(backtexture);

	//Ship
	Ship ship;
	ship.setlocation(348, 495);

	//Enemies
	Enemy enemy0 = Enemy(200, 100);
	Enemy enemy1 = Enemy(600, 100);
	Enemy enemy2 = Enemy(200, 150);
	Enemy enemy3 = Enemy(600, 150);
	Enemy enemy4 = Enemy(200, 200);
	Enemy enemy5 = Enemy(600, 200);
	Enemy enemy6 = Enemy(200, 250);
	Enemy enemy7 = Enemy(600, 250);

	//Bullets
	Bullet bullet0;
	Bullet bullet1;
	Bullet bullet2;
	Bullet bullet3;
	Bullet bullet4;
	Bullet bullet5;
	Bullet bullet6;
	Bullet bullet7;

	bullet0.setlocation(enemy0.getsprite().getPosition().x, enemy0.getsprite().getPosition().y + 12);
	bullet1.setlocation(enemy1.getsprite().getPosition().x, enemy1.getsprite().getPosition().y + 12);
	bullet2.setlocation(enemy2.getsprite().getPosition().x, enemy2.getsprite().getPosition().y + 12);
	bullet3.setlocation(enemy3.getsprite().getPosition().x, enemy3.getsprite().getPosition().y + 12);
	bullet4.setlocation(enemy4.getsprite().getPosition().x, enemy4.getsprite().getPosition().y + 12);
	bullet5.setlocation(enemy5.getsprite().getPosition().x, enemy5.getsprite().getPosition().y + 12);
	bullet6.setlocation(enemy6.getsprite().getPosition().x, enemy6.getsprite().getPosition().y + 12);
	bullet7.setlocation(enemy7.getsprite().getPosition().x, enemy7.getsprite().getPosition().y + 12);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Draw
		window.draw(backsprite);
		window.draw(ship.getsprite());
		enemy0.draw(window);
		enemy1.draw(window);
		enemy2.draw(window);
		enemy3.draw(window);
		enemy4.draw(window);
		enemy5.draw(window);
		enemy6.draw(window);
		enemy7.draw(window);
		bullet0.draw(window);
		bullet1.draw(window);
		bullet2.draw(window);
		bullet3.draw(window);
		bullet4.draw(window);
		bullet5.draw(window);
		bullet6.draw(window);
		bullet7.draw(window);

		
		//Movement
		ship.move();

		enemy0.leftright(0, 400);
		enemy1.leftright(400, 800);
		enemy2.leftright(0, 300);
		enemy3.leftright(300, 800);
		enemy4.leftright(0, 600);
		enemy5.leftright(600, 800);
		enemy6.leftright(0, 450);
		enemy7.leftright(450, 800);

		if (bullet0.getsprite().getPosition().y > 700){
			bullet0.setlocation(enemy0.getsprite().getPosition().x, enemy0.getsprite().getPosition().y + 12);
		}
		if (bullet1.getsprite().getPosition().y > 700) {
			bullet1.setlocation(enemy1.getsprite().getPosition().x, enemy1.getsprite().getPosition().y + 12);
		}
		if (bullet2.getsprite().getPosition().y > 700) {
			bullet2.setlocation(enemy2.getsprite().getPosition().x, enemy2.getsprite().getPosition().y + 12);
		}
		if (bullet3.getsprite().getPosition().y > 700) {
			bullet3.setlocation(enemy3.getsprite().getPosition().x, enemy3.getsprite().getPosition().y + 12);
		}
		if (bullet4.getsprite().getPosition().y > 700) {
			bullet4.setlocation(enemy4.getsprite().getPosition().x, enemy4.getsprite().getPosition().y + 12);
		}
		if (bullet5.getsprite().getPosition().y > 700) {
			bullet5.setlocation(enemy5.getsprite().getPosition().x, enemy5.getsprite().getPosition().y + 12);
		}
		if (bullet6.getsprite().getPosition().y > 700) {
			bullet6.setlocation(enemy6.getsprite().getPosition().x, enemy6.getsprite().getPosition().y + 12);
		}
		if (bullet7.getsprite().getPosition().y > 700) {
			bullet7.setlocation(enemy7.getsprite().getPosition().x, enemy7.getsprite().getPosition().y + 12);
		}

		bullet0.movedown();
		bullet1.movedown();
		bullet2.movedown();
		bullet3.movedown();
		bullet4.movedown();
		bullet5.movedown();
		bullet6.movedown();
		bullet7.movedown();

		//Shooting
		Bullet bullet;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			bullet.isalive(true);
		}
		if (bullet.getalive()) {
			bullet.setlocation(ship.getsprite().getPosition().x + 7, ship.getsprite().getPosition().y - 65);
			bullet.draw(window);
			bullet.moveup();
		}

		window.display();
	}
	return 0;
}