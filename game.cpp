#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Stage.h"
#include "text.h"
using namespace sf;

void display(RenderWindow& window, std::string fileName, std::string fireballurl, int numPics);
void displayTitleScreen(RenderWindow& window);


const double IMAGE_SIZE = 64;
const int SCRWIDTH = 1280;
const int SCRHEIGHT = 800;
struct Point
{
	int x, y;
};

int main()
{
	RenderWindow titleWindow(VideoMode(SCRWIDTH, SCRHEIGHT), "Welcome to Space Explorer!");

	displayTitleScreen(titleWindow);
	RenderWindow titleWindow1(VideoMode(SCRWIDTH, SCRHEIGHT), "Welcome to Space Explorer!");
	display(titleWindow1, "player.png", "fireball.png", 7);

	RenderWindow gameWindow(VideoMode(SCRWIDTH, SCRHEIGHT), "Space Explorer");
}



void display(RenderWindow& window, std::string fileName, std::string fireballurl, int numPics)
{
	srand(time(0));
	Point blockright[5];
	Point blockleft[5];
	for (int i = 0; i < 5; i++)
	{
		blockright[i].x = 1280 - 100;
		blockright[i].y = rand() & 734 + 33;

		blockleft[i].x = 100;
		blockleft[i].y = rand() & 734 + 33;
	}

	//Player player1;
	Texture asteroid;
	asteroid.loadFromFile("asteroid.png");
	Sprite asteroidsprite(asteroid);
	asteroidsprite.scale(0.5, 0.5);

	Texture space;
	space.loadFromFile("space.png");

	Sprite bg(space);

	Texture t1;
	t1.loadFromFile(fileName);

	Texture fireballtexture;
	fireballtexture.loadFromFile(fireballurl);

	IntRect i(0, 0, IMAGE_SIZE, IMAGE_SIZE);
	IntRect j(0, 0, IMAGE_SIZE, IMAGE_SIZE);

	Sprite s1(t1, i);
	Sprite fireball(fireballtexture, i);

	Clock c;

	bool forward = true;

	//-------------------------------------------------
	double x = 0, y = 0;
	bool fireShot = false;
	int direction = -1;
	double xSpeed = 0, ySpeed = 0, fx = x, fy = y;
	Clock timer;
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (c.getElapsedTime().asSeconds() > 0.05f)
		{
			if (forward)
				i.left += IMAGE_SIZE;
			if (i.left >= (numPics - 1) * IMAGE_SIZE) {
				forward = false;
				i.left -= IMAGE_SIZE;
			}
			if (!forward)
				i.left -= IMAGE_SIZE;
			if (i.left == 0) {
				forward = true;
				i.left += IMAGE_SIZE;
			}

			s1.setTextureRect(i);
			c.restart();
		}
		s1.setScale(2, 2);
		if (Keyboard::isKeyPressed(Keyboard::Tab)) window.close();
		if (Keyboard::isKeyPressed(Keyboard::Right) && x < 1152) x += .5, direction = 1;
		if (Keyboard::isKeyPressed(Keyboard::Left) && x > 0) x -= .5, direction = 3;
		if (Keyboard::isKeyPressed(Keyboard::Up) && y > 0) y -= .5, direction = 0;
		if (Keyboard::isKeyPressed(Keyboard::Down) && y < 672) y += .5, direction = 2;
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			fx = x;
			fy = y;

			xSpeed = 0;
			ySpeed = 0;

			if (direction == 0)
			{
				j.top = 128;
				ySpeed = -.5;
			}

			if (direction == 1)
			{
				j.top = 256;
				xSpeed = .5;
			}

			if (direction == 2)
			{
				j.top = 384;
				ySpeed = 0.5;
			}

			if (direction == 3)
			{
				j.top = 0;
				xSpeed = -.5;
			}

		}
		fx += xSpeed;
		fy += ySpeed;

		fireball.setTextureRect(j);
		fireball.setPosition(fx, fy);

		s1.setPosition(x, y);

		window.clear();
		window.draw(bg);
		window.draw(fireball);



		for (int i = 0; i < 5; i++)
		{
			srand(rand());
			if (blockright[i].x <= 0)
			{
				blockright[i].x = 1280 - 100;
				blockright[i].y = rand() & 734 + 33;
			}
			blockright[i].x = blockright[i].x - 1;

			asteroidsprite.setPosition(blockright[i].x, blockright[i].y);
			window.draw(asteroidsprite);

			srand(rand());
			if (blockleft[i].x >= 1280)
			{
				blockleft[i].x = 100;
				blockleft[i].y = rand() & 734 + 33;
			}
			blockleft[i].x += 1;
			asteroidsprite.setPosition(blockleft[i].x, blockleft[i].y);
			window.draw(asteroidsprite);
		}

		window.draw(s1);
		window.display();

	}
	RenderWindow gameOverWindow(VideoMode(SCRWIDTH, SCRHEIGHT), "Game Over!");
	Time points = timer.getElapsedTime();

	Font Roboto;
	Roboto.loadFromFile("Roboto-Regular.ttf");
	Text text("Game Over, your score is " + std::to_string(points.asMilliseconds()), Roboto, 50);
	text.setPosition((SCRWIDTH / 2) - (SCRWIDTH / 4), SCRHEIGHT / 4);

	while (gameOverWindow.isOpen())
	{
		// Process events
		sf::Event event;
		while (gameOverWindow.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				gameOverWindow.close();
		}
		// Clear screen
		gameOverWindow.clear();

		// Draw the string
		gameOverWindow.draw(text);
		// Update the window
		gameOverWindow.display();
	}
}

void displayTitleScreen(RenderWindow& window)
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	Texture background;
	background.loadFromFile("board.jpg");
	Sprite background1(background);
	Clock c;

	// Create a graphical text to display
	Font Roboto;
	Font Roboto_Bold;

	Roboto.loadFromFile("Roboto-Regular.ttf");
	Roboto_Bold.loadFromFile("Roboto-Bold.ttf");

	Text text("Kareem, Jeff, Kenny, Tim, and\n Ritesh are proud to present", Roboto_Bold, 30);
	Text text1("SPACE EXPLORER", Roboto_Bold, 50);

	//center text
	text.setPosition((SCRWIDTH / 2) - (SCRWIDTH / 4), SCRHEIGHT / 4);
	text1.setPosition((SCRWIDTH / 2) - (SCRWIDTH / 4), (SCRHEIGHT / 2));

	// Start the game loop
	double a = 255, b = 0, scaleX = 1.02, scaleY = 1.02;
	bool x = true;

	while (window.isOpen())
	{
		// Process events
		Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();

		background1.setColor(Color(255, 255, 255, a));
		text.setFillColor(Color::White);
		text1.setFillColor(Color::White);
		text.setFillColor(Color(255, 255, 255, a));
		text1.setFillColor(Color(255, 255, 255, b));

		if (a >= 0.5) a -= 0.5;

		Time t = c.getElapsedTime();

		window.draw(background1);
		window.draw(text);
		if (t > seconds(3))
		{
			if (b > 150) x = false;
			if (x) b++;
			if (!x && b >= 1) b--;
			window.draw(text1);
		}
		if (a <= 10) window.close();


		window.display();
	}
}