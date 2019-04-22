#include "Time.h"
#include <SDL.h>

namespace breakout
{
	Time* Time::instance = nullptr;

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
	double Time::GetDeltaTime()
	{
		double currentUpdateTime = GetTime();
		double deltaTime = currentUpdateTime - previousUpdateTime;
		previousUpdateTime = currentUpdateTime;
		return deltaTime;
	}
	int Time::GetFPS() const
	{
		return fps;
	}
	int Time::GetUPS() const
	{
		return ups;
	}
	void Time::AddFrameCount()
	{
		frames++;
	}
	void Time::AddUpdateCount()
	{
		updates++;
	}
	bool Time::UpdatePerSecCounters()
	{
		double currentPerSecTime = GetTime();
		if (currentPerSecTime - previousPerSecTime >= 1000.0)
		{
			fps = frames;
			frames = 0;
			ups = updates;
			updates = 0;
			previousPerSecTime = currentPerSecTime;
			return true;
		}
		return false;
	}
	Time::~Time()
	{
		
	}
}
