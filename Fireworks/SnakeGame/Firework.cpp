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
		m_particles.emplace_back(m_master.GetPosition().x, m_master.GetPosition().y);
	}
}


