#pragma once
#include <iostream>
#include "Constants.h"
#include "SFML/Graphics.hpp"


class Particle {
public:
	explicit Particle(const float _x, const float _y)
	{
		const float vel = static_cast<float>(constants::random_range(6, 10)) / 100;
		m_velocity.y = -vel;
		m_position.x = _x;
		m_position.y = _y;
		m_shape.setRadius(5);
	};

	sf::Vector2f GetVelocity() const { return m_velocity; }
	sf::Vector2f GetPosition() const { return m_position; }

	void Update();

	void ApplyForce(sf::Vector2f _force);

	void Render(sf::RenderWindow& _window) {
		m_shape.setFillColor(sf::Color::Green);
		m_shape.setPosition(m_position);
		_window.draw(m_shape);
	}
private:
	sf::CircleShape m_shape;
	
	sf::Vector2f m_position;
	sf::Vector2f m_velocity{0, -0.09f};
	sf::Vector2f m_acceleration;

};

