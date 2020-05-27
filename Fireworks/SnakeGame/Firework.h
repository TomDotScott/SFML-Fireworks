#pragma once
#include "Particle.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"

class Firework {
public:
	Firework()
	{
		m_particles.emplace_back(650, 720);
	};
	void Update();
	void Render(sf::RenderWindow& _window);
	
private:
	bool m_exploded{ false };
	std::vector<Particle> m_particles;
	Particle m_master{static_cast<float>(rand() % constants::k_screenWidth), constants::k_screenHeight};
	sf::Vector2f m_gravity{ 0, 0.000008f};
};

