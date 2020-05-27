#include "Particle.h"

void Particle::Update() {
	m_velocity += m_acceleration;
	m_shape.setPosition(m_velocity + m_shape.getPosition());

	//Reset acceleration
	m_acceleration.x = 0;
	m_acceleration.y = 0;
}

void Particle::ApplyForce(sf::Vector2f _force)
{
	m_acceleration += _force;
}
