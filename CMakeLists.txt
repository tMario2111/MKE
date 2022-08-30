cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(mke)

add_library(mke
	source/Animation.hpp source/Animation.cpp
	source/AssetManager.hpp source/AssetManager.cpp
	source/Input.hpp source/Input.cpp
	source/Random.hpp source/Random.cpp
	source/ShadowCaster.hpp source/ShadowCaster.cpp
	source/SoundManager.hpp source/SoundManager.cpp 
	source/SpriteBatch.hpp source/SpriteBatch.cpp
	source/State.hpp source/StateMachine.hpp
	source/Utility.hpp source/Utility.cpp)

find_package(SFML COMPONENTS window graphics system audio CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(mke PRIVATE
	sfml-graphics sfml-system sfml-window sfml-audio
	nlohmann_json nlohmann_json::nlohmann_json)