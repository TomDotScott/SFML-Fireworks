#pragma once
#include <iostream>
#include "Constants.h"
#include "SFML/Graphics.hpp"


class Particle {
public:
	Particle() = default;
	
	Particle(const sf::Vector2f& _position, const sf::Vector2f& _initialVelocity, const float _size, const sf::Color _colour) : m_position(_position), m_velocity(_initialVelocity)
	{
		m_shape.setFillColor(_colour);
		m_shape.setRadius(_size);
	};

	sf::Vector2f GetVelocity() const { return m_velocity; }
	sf::Vector2f GetPosition() const { return m_position; }
	sf::Color GetColour() const { return m_shape.getFillColor(); }

	
	void SetPosition(const sf::Vector2f _position)
	{
		m_position.x = _position.x;
		m_position.y = _position.y;
	}

	void SetVelocity(const sf::Vector2f _velocity) {
		m_position.x = _velocity.x;
		m_position.y = _velocity.y;
	}
	
	void Update();

	void ApplyForce(sf::Vector2f _force);

	void Render(sf::RenderWindow& _window) {
		m_shape.setPosition(m_position);
		_window.draw(m_shape);
	}
private:
	sf::CircleShape m_shape;
	
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;

};

