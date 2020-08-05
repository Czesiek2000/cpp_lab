#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	/*sf::RectangleShape rectangle(sf::Vector2f(10.0f, 10.0f));
	rectangle.setFillColor(sf::Color::Red);
	float width = 0.0f;
	float height = 0.0f;
	rectangle.setPosition(width, height);*/

	sf::Event event;

	srand(time(0));

	RectangleShape rectangle1;
	RectangleShape rectangle2;
	RectangleShape rectangle3;
	RectangleShape rectangle4;

	rectangle1.setSize(sf::Vector2f(30, 30));
	rectangle1.setFillColor(Color::White);
	rectangle1.setPosition((rand() % 7) * 100, (rand() % 6) * 200);
	std::cout << (rand() % 7) * 100 << " " << (rand() % 6) * 200 << std::endl;

	rectangle2.setSize(sf::Vector2f(30, 30));
	rectangle2.setFillColor(Color::Green);
	rectangle2.setPosition((rand() % 4) * 400, (rand() % 4) * 400);
	std::cout << (rand() % 4) * 400 << " " << (rand() % 4) * 400 << std::endl;

	rectangle3.setSize(sf::Vector2f(30, 30));
	rectangle3.setFillColor(Color::Yellow);
	rectangle3.setPosition((rand() % 5) * 400, (rand() % 4) * 200);
	std::cout << (rand() % 5) * 400 << " " << (rand() % 4) * 200 << std::endl;

	rectangle4.setSize(sf::Vector2f(30, 30));
	rectangle4.setFillColor(Color::Magenta);
	rectangle4.setPosition((rand() % 3) * 300, (rand() % 3) * 100);
	std::cout << (rand() % 3) * 300 << " " << (rand() % 3) * 100 << std::endl;
	while (window.isOpen()) 
	{
		
		while (window.pollEvent(event))
		{
			//window.clear(Color::White);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				double x = event.mouseButton.x;
				double y = event.mouseButton.y;
				if (event.key.code == sf::Mouse::Left) {
					RectangleShape rectangle;
					rectangle.setSize(sf::Vector2f(10, 10));
					rectangle.setFillColor(Color::Blue);
					rectangle.setPosition(x, y);
					std::cout << "Create rectangle " << std::endl;
					window.draw(rectangle);
				}

				if (event.key.code == sf::Mouse::Right)
				{
					CircleShape circle;
					circle.setRadius(10);
					circle.setFillColor(Color::Green);
					circle.setPosition(x, y);
					std::cout << "Create circle" << std::endl;
					window.draw(circle);
				}
			}

				window.display();
		}


		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectangle3);
		window.draw(rectangle4);

	}

	return 0;
}

