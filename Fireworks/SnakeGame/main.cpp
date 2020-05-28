#include <SFML/Graphics.hpp>
#include "Firework.h"
#include "Constants.h"

int main() {
	sf::Clock clock;
	srand(time(nullptr));

	// Create an instance of the SFML RenderWindow type which represents the display
	// and initialise its size and title text
	sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "SFML Fireworks");

	std::vector<Firework> fireworks;

	for(int i = 0; i < 10; ++i)
	{
		Firework fw({ static_cast<float>(constants::random_range(0, constants::k_screenWidth)), constants::k_screenHeight },
			{ 0, static_cast<float>(constants::random_range(5, 10)) / 10 },
			{ static_cast<uint8_t>(constants::random_range(0, 255)),
			   static_cast<uint8_t>(constants::random_range(0, 255)),
			   static_cast<uint8_t>(constants::random_range(0, 255))
			});
		fireworks.emplace_back(fw);
	}

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


		for (auto& firework : fireworks)
		{
			if(firework.HasFinished())
			{
				firework.Reset();
			}
			firework.Update();
			firework.Render(window);
		}
			
		// Get the window to display its contents
		window.display();
	}

	return 0;
}
