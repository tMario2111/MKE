#pragma once

#include <iostream>
#include <random>

namespace mke
{

	/// <summary>
	/// A class that wraps <random> and uses std::default_random_engine
	/// </summary>
	class Random
	{
	public:

		/// <summary>
		/// Set a new custom seed 
		/// </summary>
		/// <param name="seed">: The seed</param>
		void setCustomSeed(unsigned long int seed);

		/// <summary>
		/// Sets a new unique seed (using std::random_device)
		/// </summary>
		void setUniqueSeed();

		/// <summary>
		/// Get the engine's seed
		/// </summary>
		/// <returns>Engine's seed</returns>
		unsigned long int getSeed();

		/// <summary>
		/// Get a random integer
		/// </summary>
		/// <typeparam name="T">: Integer type</typeparam>
		/// <param name="min">: Minimum value</param>
		/// <param name="max">: Maximum value</param>
		/// <returns>A random integer</returns>
		template<typename T> T getInt(T min, T max);

		/// <summary>
		/// Get a random real number
		/// </summary>
		/// <typeparam name="T">: Real type</typeparam>
		/// <param name="min">: Minimum value</param>
		/// <param name="max">: Maximum value</param>
		/// <returns>A random real</returns>
		template<typename T> T getReal(T min, T max);
	private:
		std::random_device r;
		std::default_random_engine random_engine;
		unsigned long int seed;
	};
	template<typename T> inline T Random::getInt(T min, T max)
	{
		if (min >= max)
		{
			std::cerr << "Error: mke::Random::getInt(): max must be greater than min\n";
			exit(-1);
		}
		return std::uniform_int_distribution<T>(min, max)(random_engine);
	}
	template<typename T> inline T Random::getReal(T min, T max)
	{
		if (min >= max)
		{
			std::cerr << "Error: mke::Random::getReal(): max must be greater than min\n";
			exit(-1);
		}
		return std::uniform_real_distribution<T>(min, max)(random_engine);
	}
}

