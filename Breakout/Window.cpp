#include "Window.h"
#include <iostream>

using namespace std;

namespace breakout
{
	static Window* instance = nullptr;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool successfullyCreated = false;
	const int width = 1280;
	const int height = 720;

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
		SDL_RenderCopy(renderer, object->GetTexture(), nullptr, object->GetRect());
	}
	void Window::RenderUpdate()
	{
		SDL_RenderPresent(renderer);
		Clear();
	}
	Window::~Window()
	{
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
