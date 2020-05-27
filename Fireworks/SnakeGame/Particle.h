#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"


class Particle {
public:
	explicit Particle(const float _x, const float _y)
	{
		const float vel = static_cast<float>((6 + (rand() % (10 - 6 + 1)))) / 100;
		m_velocity.y = -vel;
		m_shape.setPosition({ _x, _y });
		m_shape.setRadius(5);
		m_shape.setFillColor(sf::Color::Green);
	};

	sf::Vector2f GetVelocity() const { return m_velocity; }
	
	void Update();

	void Render(sf::RenderWindow& _window) const
	{
		_window.draw(m_shape);
	}

	void ApplyForce(sf::Vector2f _force);
	
private:
	sf::CircleShape m_shape;
	
	sf::Vector2f m_position;
	sf::Vector2f m_velocity{0, -0.09f};
	sf::Vector2f m_acceleration;

};

