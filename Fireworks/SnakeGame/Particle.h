#pragma once
#include "SFML/Graphics.hpp"

enum class EType {
	eRocket, eParticles
};

class Particle {
public:
	Particle() = default;

	Particle(const sf::Vector2f& _position, const sf::Vector2f& _initialVelocity, const float _size, const sf::Color _colour, const EType _type) :
		m_colour(_colour),
		m_position(_position),
		m_velocity(_initialVelocity),
		m_type(_type) {
		m_shape.setRadius(_size);
	};

	sf::Vector2f GetVelocity() const { return m_velocity; }
	sf::Vector2f GetPosition() const { return m_position; }
	sf::Color GetColour() const { return m_shape.getFillColor(); }

	bool GetDead() const { return m_dead; }

	void SetPosition(const sf::Vector2f _position) {
		m_position.x = _position.x;
		m_position.y = _position.y;
	}

	void SetVelocity(const sf::Vector2f _velocity) {
		m_position.x = _velocity.x;
		m_position.y = _velocity.y;
	}

	void SetColour(const uint8_t _r, const uint8_t _g, const uint8_t _b)
	{
		m_colour = { _r, _g, _b };
	}

	void Update();

	void ApplyForce(sf::Vector2f _force);

	void Render(sf::RenderWindow& _window) {
		m_shape.setFillColor(m_colour);
		m_shape.setPosition(m_position);
		_window.draw(m_shape);
	}
private:
	sf::Color m_colour;
	sf::CircleShape m_shape;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	EType m_type;
	bool m_dead{ false };
};

