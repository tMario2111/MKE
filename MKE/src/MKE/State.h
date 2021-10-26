#pragma once

namespace mke
{
	class State
	{
	public:
		virtual void update() = 0;
		virtual void render() = 0;
	};
}