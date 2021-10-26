#pragma once

#include "State.h"

#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

namespace mke
{	

	/// <summary>
	/// a state machine class 
	/// </summary>
	class StateMachine
	{
	public:

		/// <summary>
		/// Push a new state to the stack
		/// </summary>
		/// <typeparam name="T">State type</typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args">State constructor arguments</param>
		template<typename T, typename... Args> void push(Args &&... args);

		/// <summary>
		/// Pop the state at the top of the stack
		/// </summary>
		void pop();

		/// <summary>
		/// Pop states off the stack until a state of type 'T' is reached 
		/// </summary>
		/// <typeparam name="T">State type</typeparam>
		template<typename T> void popStatesUntil();

		/// <summary>
		/// Get a reference to the state at the top of the stack
		/// </summary>
		/// <returns>Top state</returns>
		State& top();

		/// <summary>
		/// Get the size of the stack
		/// </summary>
		/// <returns>Size of the stack</returns>
		std::size_t size();

		/// <summary>
		/// Get a reference to the first state of type 'T' that isn't at the top of the stack
		/// </summary>
		/// <typeparam name="T">State type</typeparam>
		/// <returns>A reference to the state</returns>
		template<typename T> T& peekFirst();

	private:
		std::vector<std::unique_ptr<State>> states;
	};

	template<typename T, typename ...Args> inline void StateMachine::push(Args && ...args)
	{
		states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
	}

	template<typename T> inline void StateMachine::popStatesUntil()
	{
		while (states.size() && typeid(T) != typeid(*states.back().get()))
			states.pop_back();
	}

	template<typename T> inline T& StateMachine::peekFirst()
	{
		for (unsigned int i = states.size() - 2; i >= 0; i--)
			if (typeid(T) == typeid(*states[i].get()))
				return *dynamic_cast<T*>(states[i].get());
		std::cerr << "Error: mke::StateMachine::peekFirst(): peeked state doesn't exist in the stack\n";
		exit(-1);
	}
}

