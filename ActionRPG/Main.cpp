#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 200), "SFML Template");
	sf::Text message;

	// Load the font
	sf::Font font;
	font.loadFromFile("font.ttf");

	// Set the message font, string, size, and color
	message.setFont(font);
	message.setString("Hello World");
	message.setCharacterSize(125);
	message.setFillColor(sf::Color::White);

	// Game loop
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(message);
		window.display();
	}

	return 0;
}