
#include "../../MKE/src/MKE/StateMachine.h"
#include <iostream>
 
class State1 : public mke::State
{
public:
	virtual void update() 
	{
		std::cout << "State1\n";
	};
	virtual void render() {};
	int x = 10;
private:
};

class State2 : public mke::State
{
public:
	virtual void update() 
	{
		std::cout << "State2\n";
	};
	virtual void render() {};
private:
};

int main()
{
	mke::StateMachine states;

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

	return 0;
}