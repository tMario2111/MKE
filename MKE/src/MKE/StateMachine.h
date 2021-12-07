#pragma once

#include "State.h"

#include <iostream>
#include <memory>
#include <type_traits>
#include <typeinfo>
#include <vector>

namespace mke
{

	/// <summary>
	/// A state machine class
	/// </summary>
	/// <typeparam name="Base">: The default base is mke::State, but you can use a custom one</typeparam>
	template<typename Base = State> class StateMachine
	{
	public:

		/// <summary>
		/// Push a new state to the stack
		/// </summary>
		/// <typeparam name="T">: State type</typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args">: State constructor arguments</param>
		template<typename T, typename... Args,
			typename std::enable_if_t<std::is_base_of<Base, T>::value, bool> = true>
			void push(Args &&... args);

		/// <summary>
		/// Pop the state at the top of the stack
		/// </summary>
		void pop();

		/// <summary>
		/// Pop states off the stack until a state of type 'T' is reached 
		/// </summary>
		/// <typeparam name="T">: State type</typeparam>
		template<typename T, typename std::enable_if_t<std::is_base_of<Base, T>::value, bool> = true>
		void popStatesUntil();

		/// <summary>
		/// Get a reference to the state at the top of the stack
		/// </summary>
		/// <returns>Top state</returns>
		Base& top();

		/// <summary>
		/// Get the size of the stack
		/// </summary>
		/// <returns>Size of the stack</returns>
		std::size_t size();

		/// <summary>
		/// Get a reference to the first state of type 'T' that isn't at the top of the stack
		/// </summary>
		/// <typeparam name="T">: State type</typeparam>
		/// <returns>A reference to the state</returns>
		template<typename T, std::enable_if_t<std::is_base_of<Base, T>::value, bool> = true>
		T& peekFirst();

	private:
		std::vector<std::unique_ptr<Base>> states;
	};

	template<typename Base>
	template<typename T, typename... Args,
		typename std::enable_if_t<std::is_base_of<Base, T>::value, bool>>
		inline void StateMachine<Base>::push(Args && ...args)
	{
		states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
	}

	template<typename Base>
	template<typename T, typename std::enable_if_t<std::is_base_of<Base, T>::value, bool>>
	inline void StateMachine<Base>::popStatesUntil()
	{
		while (states.size() && typeid(T) != typeid(*states.back().get()))
			states.pop_back();
	}

	template<typename Base>
	template<typename T, std::enable_if_t<std::is_base_of<Base, T>::value, bool>>
	inline T& StateMachine<Base>::peekFirst()
	{
		for (unsigned int i = states.size() - 2; i >= 0; i--)
			if (typeid(T) == typeid(*states[i].get()))
				return *dynamic_cast<T*>(states[i].get());
		std::cerr << "Error: mke::StateMachine::peekFirst(): peeked state doesn't exist in the stack\n";
		exit(-1);
	}

	template<typename Base>
	inline void StateMachine<Base>::pop()
	{
		states.pop_back();
	}

	template<typename Base>
	inline Base& StateMachine<Base>::top()
	{
		if (states.size() == 0)
		{
			std::cerr << "Error: mke::StateMachine::top(): stack is empty\n";
			exit(-1);
		}
		return *states.back().get();
	}

	template<typename Base>
	inline std::size_t StateMachine<Base>::size()
	{
		return states.size();
	}
}

