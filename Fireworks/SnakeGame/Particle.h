#pragma once
#include "SFML/Graphics.hpp"


class Particle {
public:
	explicit Particle(float _x, float _y)
	{
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
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;

};

