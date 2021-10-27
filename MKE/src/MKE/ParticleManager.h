#pragma once

#include <SFML/Graphics.hpp>

#include "Random.h"
#include "Utility.h"

#include <algorithm>
#include <list>
#include <utility>
#include <vector>

namespace mke
{
	/// <summary>
	/// A particle manager class
	/// </summary>
	class ParticleManager : public sf::Drawable
	{
	public:

		/// <summary>
		/// Default constructor 
		/// </summary>
		ParticleManager();

		struct Particle
		{
			sf::Vector2f position;
			sf::Vector2f velocity;
			sf::Color color;
			sf::Time lifetime;
			sf::Time lifetime_clock = sf::seconds(0.f);
		};

		/// <summary>
		/// Emitter structure (emits particles)
		/// </summary>
		struct Emitter
		{

			/// <summary>
			/// Default constructor 
			/// </summary>
			Emitter();

			/// <summary>
			/// Copy settings constructor
			/// </summary>
			/// <param name="settings">: A reference to another emitter (to copy the settings from)</param>
			Emitter(const Emitter& settings);

			/// <summary>
			/// Particles' spawn position
			/// </summary>
			sf::Vector2f position;

			/// <summary>
			/// Particles' moving direction
			/// </summary>
			float direction;

			/// <summary>
			/// Particles' lifetime range (first is min, second is max)
			/// </summary>
			std::pair<sf::Time, sf::Time> lifetime_range;

			/// <summary>
			/// A vector of colors (a particle randomly selects one of them)
			/// </summary>
			std::vector<sf::Color> colors;

			/// <summary>
			/// The offset is added to the direction and is randomly selected (first is min, second is max)
			/// </summary>
			std::pair<float, float> direction_offset;

			/// <summary>
			/// Particles' speed range (first is min, second is max)
			/// </summary>
			std::pair<float, float> speed_range;

			/// <summary>
			/// Particles that spawn in a second (randomly selected, first is min, second is max)
			/// </summary>
			std::pair<unsigned int, unsigned int> particles_per_second;

			/// <summary>
			/// Emitter's state (active or inactive)
			/// </summary>
			bool active = false;
		};


		/// <summary>
		/// Add a new Emitter 
		/// </summary>
		/// <param name="emitter">: A reference to an emitter</param>
		void addEmitter(Emitter& emitter);

		/// <summary>
		/// Erase an Emitter
		/// </summary>
		/// <param name="emitter">: A reference to the emitter that's going to be erased</param>
		void eraseEmitter(Emitter& emitter);

		/// <summary>
		/// Update the particles (must be called every frame)
		/// </summary>
		/// <param name="dt">: Delta time</param>
		void update(const sf::Time dt);

		/// <summary>
		/// Draws the particles (inherited from sf::Drawable)
		/// </summary>
		/// <param name="target">: The sf::RenderTarget</param>
		/// <param name="states">: The sf::RenderStates</param>
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		std::list<Particle> particles;
		std::vector<Emitter*> emitters;
		sf::VertexArray batch;
		mke::Random random;
		void createParticles(const sf::Time dt);
		void moveParticles(const sf::Time dt);
		void deleteParticles(const sf::Time dt);
		void updateBatch();
	};
}
