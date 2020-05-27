#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"


class Particle {
public:
	explicit Particle(const float _x, const float _y)
	{
		const float vel = static_cast<float>((6 + (rand() % (10 - 6 + 1)))) / 100;
		std::cout << "RANDOM : " << vel << std::endl;

		m_velocity.y = -vel;
		std::cout << "VECLOCITY " << m_velocity.y << std::endl;
		
		m_shape.setPosition({ _x, _y });
		m_shape.setRadius(5);
		m_shape.setFillColor(sf::Color::Green);
	};

	void Update();

	void Render(sf::RenderWindow& _window) const
	{
		_window.draw(m_shape);
	}
	
private:
	void ApplyForce(sf::Vector2f _force);
	sf::CircleShape m_shape;
	
	sf::Vector2f m_position;
	sf::Vector2f m_velocity{0, -0.09};
	sf::Vector2f m_acceleration;

	sf::Vector2f m_gravity{ 0, 0.000008 };
};

