#pragma once
#include "Particle.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"

class Firework {
public:
	explicit Firework(const sf::Vector2f _position, const sf::Vector2f _velocity, const sf::Color _colour) : m_master(_position, { _velocity.x, _velocity.y * -1 }, constants::random_range(1, 10), _colour) {}
	void Update();
	void Render(sf::RenderWindow& _window);
	
private:
	void Explode();

	
	bool m_exploded{ false };
	std::vector<Particle> m_particles;
	Particle m_master;
	sf::Vector2f m_gravity{ 0, 0.0009f};
};

