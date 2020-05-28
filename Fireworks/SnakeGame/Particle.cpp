#include "Particle.h"
#include "Constants.h"

void Particle::Update() {
	m_velocity += m_acceleration;
	m_position += m_velocity;

	//Reset acceleration
	m_acceleration.x = 0;
	m_acceleration.y = 0;

	//change opacity
	if (m_type == EType::eParticles) {
		m_colour.a -= static_cast<float>(constants::random_range(3, 8)) / 10;
		if (m_colour.a <= 0) {
			m_dead = true;
		}
	}

}

void Particle::ApplyForce(const sf::Vector2f _force) {
	m_acceleration += _force;
}


