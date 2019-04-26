#include "Window.h"
#include <iostream>
#include "Vector2f.h"

using namespace std;

namespace breakout
{
	Window* Window::instance = nullptr;

	Window::Window()
	{
		SDL_Init(SDL_INIT_VIDEO);
		if (SDL_WasInit(SDL_INIT_VIDEO) != SDL_INIT_VIDEO)
		{
			return;
		}
		window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if (window == nullptr)
		{
			cerr << "Failed to create window: " << SDL_GetError() << endl;
			return;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr)
		{
			cerr << "Failed to create renderer: " << SDL_GetError() << endl;
			return;
		}
		rect = new SDL_Rect();
		successfullyCreated = true;
	}
	Window* Window::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Window();
			if (!instance->IsSuccessfullyCreated())
			{
				delete instance;
				instance = nullptr;
			}
		}
		return instance;
	}
	bool Window::IsSuccessfullyCreated() const
	{
		return successfullyCreated;
	}
	int Window::GetWidth() const
	{
		return width;
	}
	int Window::GetHeight() const
	{
		return height;
	}
	int Window::GetMonitorRefreshRate() const
	{
		SDL_DisplayMode displayMode;
		if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0)
		{
			cout << "Could not find the refresh rate for the monitor. Using 60Hz as default." << endl;
			return 60;
		}
		return displayMode.refresh_rate;
	}
	void Window::SetDrawColor(Uint8 red, Uint8 green, Uint8 blue)
	{
		SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
	}
	void Window::Clear()
	{
		SDL_RenderClear(renderer);
	}
	SDL_Texture* Window::CreateTextureFromSurface(SDL_Surface* surface)
	{
		return SDL_CreateTextureFromSurface(renderer, surface);
	}
	void Window::RenderObject(GameObject* object)
	{
		Vector2f objPos = object->GetPosition();
		Vector2f objSize = object->GetSize();
		rect->x = static_cast<int>(objPos.x);

		//Flips y-axis on screen. Origo is in the lower left corner
		rect->y = height - static_cast<int>(objSize.y + objPos.y);

		rect->w = static_cast<int>(objSize.x);
		rect->h = static_cast<int>(objSize.y);
		SDL_RenderCopy(renderer, object->GetTexture(), nullptr, rect);
	}
	void Window::RenderUpdate()
	{
		SDL_RenderPresent(renderer);
		Clear();
	}
	Window::~Window()
	{
		delete rect;
		rect = nullptr;
		if (renderer != nullptr)
		{
			SDL_DestroyRenderer(renderer);
			renderer = nullptr;
		}
		if (window != nullptr)
		{
			SDL_DestroyWindow(window);
			window = nullptr;
		}
	}
}
