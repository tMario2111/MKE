
#include "../../source/StateMachine.hpp"

#include <iostream>
 
class State1 : public mke::State
{
public:
	void update() override 
	{
		std::cout << "State1\n";
	};
	void render() override {};

	int x = 10;
};

class State2 : public mke::State
{
public:
	void update() override 
	{
		std::cout << "State2\n";
	};
	void render() override {};
};

int main()
{
	mke::StateMachine states{};

	states.push<State1>();
	states.push<State2>();
	states.top().update(); // "State2";

	states.pop();
	states.top().update(); // "State1"

	for (int i = 0; i < 25; i++)
		states.push<State2>();
	states.popStatesUntil<State1>();
	states.top().update(); // "State1"

	states.push<State2>();
	std::cout << states.peekFirst<State1>().x << '\n'; // "10"

	states.pop();
	states.push<State1>();
	auto state = states.tryPeekFirst<State2>();
	if (state.has_value())
		std::cout << "State is in stack\n";
	else 
		std::cout << "State is not in stack\n";

	return 0;
}