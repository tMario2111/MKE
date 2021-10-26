#pragma once

#include <iostream>
#include <random>

namespace mke
{

	/// <summary>
	/// a class that wraps <random> and uses std::default_random_engine
	/// </summary>
	class Random
	{
	public:

		/// <summary>
		/// set a new custom seed 
		/// </summary>
		/// <param name="seed">the seed</param>
		void setCustomSeed(unsigned long int seed);

		/// <summary>
		/// sets a new unique seed (using std::random_device)
		/// </summary>
		void setUniqueSeed();

		/// <summary>
		/// get the engine's seed
		/// </summary>
		/// <returns>engine's seed</returns>
		unsigned long int getSeed();

		/// <summary>
		/// get a random integer
		/// </summary>
		/// <typeparam name="T">integer type</typeparam>
		/// <param name="min">minimum value</param>
		/// <param name="max">maximum value</param>
		/// <returns>a random integer</returns>
		template<typename T> T getInt(T min, T max);

		/// <summary>
		/// get a random real number
		/// </summary>
		/// <typeparam name="T">real type</typeparam>
		/// <param name="min">minimum value</param>
		/// <param name="max">maximum value</param>
		/// <returns>a random real</returns>
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

