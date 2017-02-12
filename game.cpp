#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Stage.h"
#include "text.h"
using namespace sf;

void display(RenderWindow& window, std::string fileName);
void displayTitleScreen(RenderWindow& window);

const double IMAGE_SIZE = 64;
const int SCRWIDTH = 1280;
const int SCRHEIGHT = 800;

int main()
{
	RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "Space");
	//display(window, "player.png");
	displayTitleScreen(window);
}

void display(RenderWindow& window, std::string fileName)
{
	Texture t1;
	t1.loadFromFile(fileName);

	IntRect i(0, 700, IMAGE_SIZE, IMAGE_SIZE);

	Sprite s1(t1, i);

	Clock c;

	bool forward = true;

	//-------------------------------------------------

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
			if (i.left >= 512) {
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
		text.setColor(Color(255, 255, 255, a));
		text1.setColor(Color(255, 255, 255, b));

		if (a >= 0.5) a -= 0.5;

		Time t = c.getElapsedTime();

		window.draw(background1);
		window.draw(text);
		if (t > seconds(3))
		{
			if (b < 255) b++;
			window.draw(text1);			
		}
			window.display();
	}
}
