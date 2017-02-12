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
	Point block[20];
	for (int i = 0; i<20; i++)
	{
		block[i].x = 1280-100;
		block[i].y = rand() & 734 + 33;
	}
	//std::cout << block[0].x << " " << block[0].y;
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

	Sprite s1(t1, i);
	Sprite fireball(fireballtexture, i);

	Clock c;

	bool forward = true;

	//-------------------------------------------------
	double x = 0, y = 0;
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
		if (Keyboard::isKeyPressed(Keyboard::Right) && x < 1152) x += .5;
		if (Keyboard::isKeyPressed(Keyboard::Left) && x > 0) x -= .5;
		if (Keyboard::isKeyPressed(Keyboard::Up) && y > 0) y -= .5;
		if (Keyboard::isKeyPressed(Keyboard::Down) && y < 672) y += .5;
		s1.setPosition(x, y);
		


		window.clear();
		window.draw(bg);
		//asteroidsprite.setPosition(block[0].x, block[0].y);
		//window.draw(asteroidsprite);
		
		for (int i = 0; i < 20; i++)
		{
			if (block[i].x <= 0) block[i].x = 1280 - 100;
			block[i].x = block[i].x - 1;
			asteroidsprite.setPosition(block[i].x, block[i].y);
			window.draw(asteroidsprite);
		}
		
		window.draw(s1);
		window.display();

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

	Text text("*insert names here* are proud to present", Roboto_Bold, 30);
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