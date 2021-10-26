#pragma once

#include <SFML/System.hpp>

namespace mke
{

	/// <summary>
	/// a class that manages delta time
	/// </summary>
	class DeltaTime
	{
	public:

		/// <summary>
		/// updates the delta time (must be called at the start of the main loop)
		/// </summary>
		void update();

		/// <summary>
		/// get the delta time
		/// </summary>
		/// <returns>an sf::Time that represents the delta time</returns>
		sf::Time get();
	private:
		sf::Clock clock;
		sf::Time time = sf::seconds(0.f);
	};
}

