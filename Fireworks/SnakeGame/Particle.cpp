#include "Particle.h"

void Particle::Update() {
	m_velocity += m_acceleration;
	m_position += m_velocity;

	//Reset acceleration
	m_acceleration.x = 0;
	m_acceleration.y = 0;
}

void Particle::ApplyForce(const sf::Vector2f _force)
{
	m_acceleration += _force;
}


