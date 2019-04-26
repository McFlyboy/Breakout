#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "GameObject.h"

namespace breakout
{
	class Window
	{
	public:
		static Window* GetInstance();

		int GetWidth() const;
		int GetHeight() const;
		int GetMonitorRefreshRate() const;
		void SetDrawColor(Uint8 red, Uint8 green, Uint8 blue);
		void Clear();
		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface);
		void RenderObject(GameObject* object);
		void RenderUpdate();
		~Window();
	private:
		static Window* instance;

		bool successfullyCreated = false;
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		SDL_Rect* rect = nullptr;
		const int width = 1280;
		const int height = 720;

		Window();
		bool IsSuccessfullyCreated() const;
	};
}
#endif
