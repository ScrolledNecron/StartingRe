#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "MyGame",sf::Style::Default, settings);
	window.setActive(true);
	window.setVerticalSyncEnabled(true);


	//creating fonts and text..
	sf::Font f;
	if (!f.loadFromFile("font/SyneMono-Regular.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Welcome to the game!", f, 45);
	text.setFillColor(sf::Color::Red);
	text.setPosition(150, 0);

	
	//Creating a rectangular shape with outline stuffs
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(48, 32));
	rectangle.setPosition(400,300);
	rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setOutlineThickness(8);
	rectangle.setOutlineColor(sf::Color::Green);
	rectangle.setOrigin(rectangle.getSize() / 2.0f);


	//Creating a polygon for ffs perhaps..
	sf::CircleShape hexagon;
	hexagon.setRadius(100.f);
	hexagon.setPointCount(6);
	hexagon.setPosition(100, 100);

	//Game loop
	while (window.isOpen())
	{
		sf::Event e;

		//Checks when a player activates a certain event..
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
				//Closing the window manually cuz SFML wont why?? implement it pls.
			case sf::Event::Closed:
				window.close();
				break;

			}


			//Clearing stuffs every frame and 
			window.clear(sf::Color::Cyan);

			//Drawing stuffs to the window
			window.draw(text);
			window.draw(rectangle);
			window.draw(hexagon);

			//Displaying stuffs
			window.display();

		}
	}

	//No error  = 0 
	// -1 or 1 = error code
	return EXIT_SUCCESS;
}
