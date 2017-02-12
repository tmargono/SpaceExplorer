#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Stage.h"
#include "text.h"
using namespace sf;

void display(RenderWindow& window, std::string fileName, int numPics);
void displayTitleScreen(RenderWindow& window);
void playGame(RenderWindow& window);

const double IMAGE_SIZE = 64;
const int SCRWIDTH = 1280;
const int SCRHEIGHT = 800;

int main()
{
	RenderWindow titleWindow(VideoMode(SCRWIDTH, SCRHEIGHT), "Welcome to Space Explorer!");

	//displayTitleScreen(titleWindow);
	display(titleWindow, "player.png", 7);

	RenderWindow gameWindow(VideoMode(SCRWIDTH, SCRHEIGHT), "Space Explorer");

	//playGame(gameWindow);
}

void playGame(RenderWindow& window)
{
	Texture space;
	space.loadFromFile("space.png");

	Sprite bg(space);

	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(bg);
		window.display();
	}
}

void display(RenderWindow& window, std::string fileName, int numPics)
{
	Texture t1;
	t1.loadFromFile(fileName);

	IntRect i(0, 0, IMAGE_SIZE, IMAGE_SIZE);

	Sprite s1(t1, i);

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
		if (Keyboard::isKeyPressed(Keyboard::Right)) x += .5;
		if (Keyboard::isKeyPressed(Keyboard::Left)) x -= .5;
		if (Keyboard::isKeyPressed(Keyboard::Up)) y -= .5;
		if (Keyboard::isKeyPressed(Keyboard::Down)) y += .5;
		s1.setPosition(x, y);

		window.clear();
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