#include "../../source/Random.hpp"

int main()
{
	mke::Random random{};
	random.setUniqueSeed(); 								// Random seed
	std::cout << random.getInt<int>(0, 25) 		   << '\n'; // Random int in [0, 25]
	std::cout << random.getReal<float>(0.f, 25.f)  << '\n'; // Random float in [0.f, 25.f]
	std::cout << random.getReal<double>(0.0, 25.0) << '\n'; // Random double in [0.0, 25.0]
	std::cout << random.getSeed() 				   << '\n'; // Get the seed
	random.setCustomSeed(3205071607); 						// Set a custom seed
	return 0;
}