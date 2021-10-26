#include "ParticleManager.h"

namespace mke
{
	ParticleManager::ParticleManager() : 
		batch(sf::PrimitiveType::Points)
	{
		random.setUniqueSeed();
	}
	ParticleManager::Emitter::Emitter()
	{
	}
	ParticleManager::Emitter::Emitter(const Emitter& settings) :
		position(settings.position),
		direction(settings.direction),
		lifetime_range(settings.lifetime_range),
		colors(settings.colors),
		direction_offset(settings.direction_offset),
		speed_range(settings.speed_range),
		particles_per_second(settings.particles_per_second)
	{
	}
	void ParticleManager::addEmitter(Emitter& emitter)
	{
		emitters.push_back(&emitter);
	}
	void ParticleManager::eraseEmitter(Emitter& emitter)
	{
		for (unsigned int i = 0; i < emitters.size(); i++)
			if (emitters[i] == &emitter)
			{
				emitters.erase(emitters.begin() + i);
				break;
			}
	}
	void ParticleManager::createParticles(const sf::Time dt)
	{
		for (const Emitter* emitter : emitters)
		{
			if (emitter->active == false)
				continue;
			unsigned int p_count = random.getInt<unsigned int>
				(emitter->particles_per_second.first, emitter->particles_per_second.second);
			p_count = (unsigned int)(p_count * dt.asSeconds());
			for (unsigned int i = 0; i < p_count; i++)
			{
				Particle particle;
				particle.lifetime = sf::seconds(random.getReal<float>(emitter->lifetime_range.first.asSeconds(), 
					emitter->lifetime_range.second.asSeconds()));
				particle.position = emitter->position;
				float direction = emitter->direction;
				direction += random.getReal<float>(emitter->direction_offset.first, emitter->direction_offset.second);
				float speed = random.getReal<float>(emitter->speed_range.first, emitter->speed_range.second);
				particle.velocity.x = speed * cosf(mke::util::toRad(direction));
				particle.velocity.y = speed * sinf(mke::util::toRad(direction));
				size_t colors_count = emitter->colors.size();
				if (emitter->colors.size() > 1)
					particle.color = emitter->colors[random.getInt<unsigned int>(0, colors_count - 1)];
				else
					particle.color = emitter->colors[0];
				particles.push_back(particle);
			}
		}
	}
	void ParticleManager::moveParticles(const sf::Time dt)
	{
		for (auto& i : particles)
			i.position += sf::Vector2f(i.velocity.x * dt.asSeconds(), i.velocity.y * dt.asSeconds());
	}
	void ParticleManager::deleteParticles(const sf::Time dt)
	{
		for (auto& particle : particles)
			particle.lifetime_clock += dt;
		particles.erase(std::remove_if(particles.begin(), particles.end(), [](const Particle& particle)
			{
				return particle.lifetime_clock >= particle.lifetime;
			}), particles.end());
	}
	void ParticleManager::updateBatch()
	{
		batch.clear();
		for (const auto& particle : particles)
			batch.append(sf::Vertex(particle.position, particle.color));
	}
	void ParticleManager::update(const sf::Time dt)
	{
		createParticles(dt);
		moveParticles(dt);
		deleteParticles(dt);
		updateBatch();
	}
	void ParticleManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(batch, states);
	}
}
