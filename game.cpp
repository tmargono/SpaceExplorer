#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 600), "This is a window title!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Blue);
	shape.setPosition(100, 100);
	CircleShape shape2(200.f);
	shape2.setFillColor(Color::Green);

	// Load a sprite to display
	Texture texture;
	if (!texture.loadFromFile("player.png"))
		return EXIT_FAILURE;
	Sprite sprite(texture);

	// Create a graphical text to display
	Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	Text text("Hello SFML", font, 50);
	text.setFillColor(Color::Magenta);

	Clock c;

	Time t = c.getElapsedTime();
	Time t2 = seconds(5);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		t = c.getElapsedTime();

		window.clear();
		window.draw(shape);
		if (t < t2) window.draw(shape2);
		window.draw(sprite);
		if (t > t2) window.draw(text);
		window.display();
	}

	return 0;
}