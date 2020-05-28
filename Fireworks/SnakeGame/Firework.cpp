#include "Firework.h"

void Firework::Update() {
	//update 'master' particle
	if (!m_exploded) {
		m_master.ApplyForce(m_gravity);
		m_master.Update();
		if (m_master.GetVelocity().y >= -0.5) {
			m_exploded = true;
			Explode();
		}
	} else {
		for (auto& particle : m_particles) {
			particle.ApplyForce(m_gravity);
			particle.Update();
		}
	}
}


void Firework::Render(sf::RenderWindow& _window) {
	if (!m_exploded) {
		m_master.Render(_window);
	} else {
		for (auto& particle : m_particles) {
			particle.Render(_window);
		}
	}
}

void Firework::Reset()
{
	m_exploded = false;
	m_particles.clear();

	const sf::Vector2f newPosition({ static_cast<float>(constants::random_range(0, constants::k_screenWidth)), constants::k_screenHeight });
	const sf::Vector2f newVelocity({ 0, -static_cast<float>(constants::random_range(5, 10)) / 10 });
	const sf::Color newColour({ static_cast<uint8_t>(constants::random_range(0, 255)),
			   static_cast<uint8_t>(constants::random_range(0, 255)),
			   static_cast<uint8_t>(constants::random_range(0, 255)) });

	m_master = Particle(newPosition, newVelocity, constants::random_range(1, 10), newColour, EType::eRocket);
	
}

bool Firework::HasFinished() {
	if (m_exploded) {
		for (auto& particle : m_particles) {
			if (!particle.GetDead()) {
				return false;
			}
		}
		return true;
	}
	return false;
}


void Firework::Explode() {
	//choose amount of particles
	const int amount = constants::random_range(25, 50);
	for (int i = 0; i < amount; ++i) {
		const auto xVelocity = (static_cast<float>(constants::random_range(-20, 20))) / 10;
		const auto yVelocity = (static_cast<float>(constants::random_range(-20, 20))) / 10;
		Particle particle(m_master.GetPosition(), { xVelocity, yVelocity }, constants::random_range(3, 6), m_master.GetColour(), EType::eParticles);
		m_particles.emplace_back(particle);
	}
}


