#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"

int main()
{
    // All SFML types and functions are contained in the sf namespace

    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Fireworks");

	auto firework = new Particle(window.getSize().x / 2, window.getSize().y / 2);

	
    // Main loop that continues until we call window.close()
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.
        sf::Event event;
        while (window.pollEvent(event))
        {
          switch(event.type)
          {
            case sf::Event::Closed:
              window.close();
            break;
            default:
              break;
          }
        }

        // We must clear the window each time around the loop
        window.clear();

		firework->Update();
    	
        // draw our circle shape to the window
		firework->Render(window);

        // Get the window to display its contents
        window.display();
    }

    return 0;
}
