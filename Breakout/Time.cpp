#include "Time.h"
#include <SDL.h>

namespace breakout
{
	static Time* instance = nullptr;

	double initTime = 0.0;
	double previousUpdateTime = 0.0;
	double previousFPSTime = 0.0;
	int frames = 0;
	int fps = 0;

	Time::Time()
	{
		initTime = GetTime();
	}
	Time* Time::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Time();
		}
		return instance;
	}
	double Time::GetTime() const
	{
		return static_cast<double>(SDL_GetPerformanceCounter()) * 1000.0 / static_cast<double>(SDL_GetPerformanceFrequency()) - initTime;
	}
	float Time::GetDeltaTime()
	{
		double currentUpdateTime = GetTime();
		float deltaTime = static_cast<float>(currentUpdateTime - previousUpdateTime);
		previousUpdateTime = currentUpdateTime;
		return deltaTime;
	}
	int Time::GetFPS() const
	{
		return fps;
	}
	bool Time::UpdateFPS()
	{
		frames++;
		double currentFPSTime = GetTime();
		if (currentFPSTime - previousFPSTime >= 1000.0)
		{
			fps = frames;
			frames = 0;
			previousFPSTime = currentFPSTime;
			return true;
		}
		return false;
	}
	Time::~Time()
	{
		
	}
}
