#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

using namespace std;

class Bullet {
private:
	bool alive;
public:
	sf::Sprite bulletsprite;
	sf::Texture bullettexture;
	bool isActive;
	Bullet() {
		alive = false;
		isActive = true;
		bullettexture.loadFromFile("bullet.png");
		bulletsprite.setTexture(bullettexture);
		bulletsprite.setScale(0.5, 0.5);
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
		if (isActive) {
			win.draw(bulletsprite);
		}
		
	}
	void kill(){
		isActive = false;
	}
	void setTexture() {
		bullettexture.loadFromFile("bullet.png");
		bulletsprite.setTexture(bullettexture);
		bulletsprite.setScale(0.5, 0.5);
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
	void kill() {
		alive = false;
	}
	bool isalive() {
		return alive;
	}
	void setlocation(float x, float y) {
		enemysprite.setPosition(x, y);
	}
	void draw(sf::RenderWindow& win) {
		if (alive) {
			win.draw(enemysprite);
		}
	}
	void Collision(std::vector<Bullet> Bullets, int* Score) {
		for (int i = 0; i < Bullets.size(); i++) {
			if ((enemysprite.getPosition().x < Bullets.at(i).bulletsprite.getPosition().x + 3) && (enemysprite.getPosition().x + 60 > Bullets.at(i).bulletsprite.getPosition().x)) {
				if ((enemysprite.getPosition().y < Bullets.at(i).bulletsprite.getPosition().y +3) && (enemysprite.getPosition().y + 48 > Bullets.at(i).bulletsprite.getPosition().y)) {
					if (Bullets.at(i).isActive && alive) {
						Bullets.at(i).isActive = false;
						alive = false;
						*Score = (*Score) - 1;
					}
				}
			}
		}
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
	void kill() {
		alive = false;
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
	bool isalive() {
		return alive;
	}
	void draw(sf::RenderWindow& win) {
		if (alive) {
			win.draw(shipsprite);
		}
	}
	void Collision(Bullet bullet, int* Save) {
		if ((shipsprite.getPosition().x + 43 > bullet.bulletsprite.getPosition().x ) && (shipsprite.getPosition().x - 43 < bullet.bulletsprite.getPosition().x)) {
			if ((shipsprite.getPosition().y > bullet.bulletsprite.getPosition().y +10 ) && (shipsprite.getPosition().y < (bullet.bulletsprite.getPosition().y +30 ))) {
				*Save = (*Save) - 1;
			}
		}
	}
};

int main()
{
	vector <Bullet> Bullets;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders!");

	//Audio
	sf::Music background;
	background.openFromFile("background.wav");
	sf::Music enemyvoice;
	enemyvoice.openFromFile("enemy.wav");
	sf::Music shipgun;
	shipgun.openFromFile("shipgun.wav");


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
	Bullet bullet;
	Bullet bullet0;
	Bullet bullet1;
	Bullet bullet2;
	Bullet bullet3;
	Bullet bullet4;
	Bullet bullet5;
	Bullet bullet6;
	Bullet bullet7;

	bullet0.setlocation(enemy0.getsprite().getPosition().x +30, enemy0.getsprite().getPosition().y + 30);
	bullet1.setlocation(enemy1.getsprite().getPosition().x +30, enemy1.getsprite().getPosition().y + 30);
	bullet2.setlocation(enemy2.getsprite().getPosition().x +30, enemy2.getsprite().getPosition().y + 30);
	bullet3.setlocation(enemy3.getsprite().getPosition().x +30, enemy3.getsprite().getPosition().y + 30);
	bullet4.setlocation(enemy4.getsprite().getPosition().x +30, enemy4.getsprite().getPosition().y + 30);
	bullet5.setlocation(enemy5.getsprite().getPosition().x +30, enemy5.getsprite().getPosition().y + 30);
	bullet6.setlocation(enemy6.getsprite().getPosition().x +30, enemy6.getsprite().getPosition().y + 30);
	bullet7.setlocation(enemy7.getsprite().getPosition().x +30, enemy7.getsprite().getPosition().y + 30);

	int Score = 8;
	int Save = 3;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed )
				window.close();
		}

		background.play();

		//Collision
		enemy0.Collision(Bullets, &Score);
		enemy1.Collision(Bullets, &Score);
		enemy2.Collision(Bullets, &Score);
		enemy3.Collision(Bullets, &Score);
		enemy4.Collision(Bullets, &Score);
		enemy5.Collision(Bullets, &Score);
		enemy6.Collision(Bullets, &Score);
		enemy7.Collision(Bullets, &Score);

		ship.Collision(bullet0, &Save);
		ship.Collision(bullet1, &Save);
		ship.Collision(bullet2, &Save);
		ship.Collision(bullet3, &Save);
		ship.Collision(bullet4, &Save);
		ship.Collision(bullet5, &Save);
		ship.Collision(bullet6, &Save);
		ship.Collision(bullet7, &Save);

		//Draw
		window.draw(backsprite);
		ship.draw(window);
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

		if (bullet0.getsprite().getPosition().y > 1000 && enemy0.isalive()){
			bullet0.setlocation(enemy0.getsprite().getPosition().x +30 , enemy0.getsprite().getPosition().y + 30);
		}
		if (bullet1.getsprite().getPosition().y > 1000 && enemy1.isalive()) {
			bullet1.setlocation(enemy1.getsprite().getPosition().x +30 , enemy1.getsprite().getPosition().y + 30);
		}
		if (bullet2.getsprite().getPosition().y > 1000 && enemy2.isalive()) {
			bullet2.setlocation(enemy2.getsprite().getPosition().x +30, enemy2.getsprite().getPosition().y + 30);
		}
		if (bullet3.getsprite().getPosition().y > 1000 && enemy3.isalive()) {
			bullet3.setlocation(enemy3.getsprite().getPosition().x +30, enemy3.getsprite().getPosition().y +30);
		}
		if (bullet4.getsprite().getPosition().y >1000 && enemy4.isalive()) {
			bullet4.setlocation(enemy4.getsprite().getPosition().x +30, enemy4.getsprite().getPosition().y +30);
		}
		if (bullet5.getsprite().getPosition().y > 1000 && enemy5.isalive()) {
			bullet5.setlocation(enemy5.getsprite().getPosition().x +30, enemy5.getsprite().getPosition().y +30);
		}
		if (bullet6.getsprite().getPosition().y > 1000 && enemy6.isalive()) {
			bullet6.setlocation(enemy6.getsprite().getPosition().x +30, enemy6.getsprite().getPosition().y + 30);
		}
		if (bullet7.getsprite().getPosition().y > 1000 && enemy7.isalive()) {
			bullet7.setlocation(enemy7.getsprite().getPosition().x +30, enemy7.getsprite().getPosition().y + 30);
		}

		bullet0.movedown();
		bullet1.movedown();
		bullet2.movedown();
		bullet3.movedown();
		bullet4.movedown();
		bullet5.movedown();
		bullet6.movedown();
		bullet7.movedown();

		if (!enemy0.isalive() || !enemy1.isalive() || !enemy2.isalive() || !enemy3.isalive()) {
			enemyvoice.play();
		}
		if (!enemy4.isalive() || !enemy5.isalive() || !enemy6.isalive() || !enemy7.isalive()) {
			enemyvoice.play();
		}

		//Shooting
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			shipgun.play();
			Bullet newBullet = Bullet();
			newBullet.setlocation(ship.getsprite().getPosition().x + 42, ship.getsprite().getPosition().y - 48);
			Bullets.push_back(newBullet);
		}
		for (int i = 0; i < Bullets.size(); i++) {
			Bullets.at(i).setTexture();
			Bullets.at(i).moveup();
			Bullets.at(i).draw(window);		
		}
		if (Score==0) {
			backtexture.loadFromFile("win.jpg");
			sf::Sprite backsprite;
			backsprite.setTexture(backtexture);
			ship.kill();
			enemy0.kill();
			enemy1.kill();
			enemy2.kill();
			enemy3.kill();
			enemy4.kill();
			enemy5.kill();
			enemy6.kill();
			enemy7.kill();
			bullet0.kill();
			bullet1.kill();
			bullet2.kill();
			bullet3.kill();
			bullet4.kill();
			bullet5.kill();
			bullet6.kill();
			bullet7.kill();
			for (int i = 0; i < Bullets.size(); i++) {
				Bullets.at(i).kill();
			}
		}
		if (Save == 0) {
			backtexture.loadFromFile("youlose.jpg");
			sf::Sprite backsprite;
			backsprite.setTexture(backtexture);
			ship.kill();
			enemy0.kill();
			enemy1.kill();
			enemy2.kill();
			enemy3.kill();
			enemy4.kill();
			enemy5.kill();
			enemy6.kill();
			enemy7.kill();
			bullet0.kill();
			bullet1.kill();
			bullet2.kill();
			bullet3.kill();
			bullet4.kill();
			bullet5.kill();
			bullet6.kill();
			bullet7.kill();
			for (int i = 0; i < Bullets.size(); i++) {
				Bullets.at(i).kill();
			}
		}

		window.display();
	}
	return 0;
}