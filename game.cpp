#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Stage.h"
#include "text.h"
using namespace sf;

void display(RenderWindow& window, std::string fileName);
void displayTitleScreen();

const double IMAGE_SIZE = 64;
const int SCRWIDTH = 800;
const int SCRHEIGHT = 1280;

int main()
{
	RenderWindow window(VideoMode(1280, 800), "Space");
	//display(window, "player.png");
	displayTitleScreen();
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

void displayTitleScreen()
{
	sf::RenderWindow window(sf::VideoMode(1280, 800), "Space");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	Texture background;
	background.loadFromFile("board.jpg");
	Sprite background1(background);


	// Create a graphical text to display
	sf::Font pangolin;
	sf::Font barrio;

	sf::Text text("Space.", barrio, 30);
	sf::Text text1("Mist enveloped the ship three hours out from port.", barrio, 50);
	text.setFillColor(sf::Color::Red);

	//center text
	text.setPosition((SCRHEIGHT / 2) - 45, SCRWIDTH / 2);
	text1.setPosition(0, (SCRWIDTH / 2) - 200);

	// Start the game loop
	double a = 255;
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
		// Clear screen
		window.clear();

		if (a < 0) { window.close(); }
		background1.setColor(sf::Color(255, 255, 255, a));

		a -= 0.5;

		window.draw(background1);
		window.draw(text);
		window.draw(text1);
		window.display();
	}
}
