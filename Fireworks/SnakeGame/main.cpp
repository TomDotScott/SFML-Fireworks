#include <SFML/Graphics.hpp>
#include "Firework.h"
#include "Constants.h"

int main() {
	sf::Clock clock;
	srand(time(nullptr));

	// Create an instance of the SFML RenderWindow type which represents the display
	// and initialise its size and title text
	sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "SFML Fireworks");

	/*std::vector<Particle*> particles;

	for (int i = 0; i < random_range(1, 50); ++i) {
		auto firework = new Particle(random_range(0, window.getSize().x), window.getSize().y);
		particles.push_back(firework);
	}*/

	Firework firework;

	// Main loop that continues until we call window.close()
	while (window.isOpen()) {
		// Handle any pending SFML events
		// These cover keyboard, mouse,joystick etc.
		sf::Event event{};
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		// We must clear the window each time around the loop
		window.clear();

		firework.Update();
		firework.Render(window);

		// Get the window to display its contents
		window.display();
	}

	return 0;
}
