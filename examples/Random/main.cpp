#include "../../MKE/src/MKE/Random.h"

int main()
{
	mke::Random random;
	random.setUniqueSeed(); // random seed
	std::cout << random.getInt<int>(0, 25) << '\n'; // random int in [0, 25]
	std::cout << random.getReal<float>(0.f, 25.f) << '\n'; // random float in [0.f, 25.f]
	std::cout << random.getReal<double>(0.0, 25.0) << '\n'; // random double in [0.0, 25.0]
	std::cout << random.getSeed() << '\n'; // get the seed
	random.setCustomSeed(3205071607); // set a custom seed
	return 0;
}