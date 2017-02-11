#include <SFML/Graphics.hpp>
using namespace sf;
const int SCRWIDTH = 800;
const int SCRHEIGHT = 1280;

int displayTitleScreen()
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
	if (!pangolin.loadFromFile("Pangolin-Regular.ttf") || !barrio.loadFromFile("Barrio-Regular.ttf"))
		return EXIT_FAILURE;
	
	
	sf::Text text("Space.", barrio, 30);
	sf::Text text1("Mist enveloped the ship three hours out from port.", barrio, 50);
	text.setFillColor(sf::Color::Red);
	
	//center text
	text.setPosition((SCRHEIGHT/2)-45, SCRWIDTH/2);
	text1.setPosition(0, (SCRWIDTH / 2) - 200);

	Clock clock; //needs fixing, doesn't fade out with clock
	Time elapsed = clock.getElapsedTime();
	Time done = seconds(30);
	
	// Start the game loop
	int a = 255;
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
		
		elapsed = clock.getElapsedTime();
		if (a < 0) { window.close(); }
		background1.setColor(sf::Color(255, 255, 255, a));
		
		if (elapsed < done)
			a--;
				
		window.draw(background1);
		window.draw(text);
		window.draw(text1);
		window.display();
			
		
	}

}
int main()
{
	displayTitleScreen();
}
