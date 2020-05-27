#pragma once
#include "Particle.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"

class Firework {
public:
	void Update();
	void Render(sf::RenderWindow& _window);
	
private:
	void Explode();

	
	bool m_exploded{ false };
	std::vector<Particle> m_particles;
	Particle m_master{/*static_cast<float>(constants::random_range(50, constants::k_screenWidth))*/ 500, constants::k_screenHeight};
	sf::Vector2f m_gravity{ 0, 0.000008f};
};

