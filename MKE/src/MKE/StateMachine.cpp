#include "StateMachine.h"

namespace mke
{
	void StateMachine::pop()
	{
		states.pop_back();
	}
	State& StateMachine::top()
	{
		if (states.size() == 0)
		{
			std::cerr << "Error: mke::StateMachine::top(): stack is empty\n";
			exit(-1);
		}
		return *states.back().get();
	}
	std::size_t StateMachine::size()
	{
		return states.size();
	}
}
