#include "Firework.h"

void Firework::Update()
{
	//update 'master' particle
	if(!m_exploded)
	{
		m_master.ApplyForce(m_gravity);
		m_master.Update();
		if (m_master.GetVelocity().y >= 0) {
			m_exploded = true;
			Explode();
		}
	}
	else {
		for (auto& particle : m_particles) {
			particle.ApplyForce(m_gravity);
			particle.Update();			
		}
	}
}


void Firework::Render(sf::RenderWindow& _window)
{
	if (!m_exploded) {
		
		m_master.Render(_window);
		
	} else {
		for (auto& particle : m_particles) {
			particle.Render(_window);
		}
	}
}


void Firework::Explode()
{
	//choose amount of particles
	const int amount = constants::random_range(25, 50);
	for(int i = 0; i < amount; ++i)
	{
		//m_particles.emplace_back(m_master.GetPosition().x, m_master.GetPosition().y);
		const auto xVelocity = (static_cast<float>(constants::random_range(-9, 9))) / 10;
		const auto yVelocity = (static_cast<float>(constants::random_range(-9, 9))) / 10;
		Particle particle(m_master.GetPosition(), {xVelocity, yVelocity}, constants::random_range(3, 6), m_master.GetColour());
		m_particles.emplace_back(particle);		
	}
}


