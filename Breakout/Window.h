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
		int GetTargetFPS() const;
		void SetDrawColor(Uint8 red, Uint8 green, Uint8 blue);
		void Clear();
		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface);
		void RenderObject(GameObject* object);
		void RenderUpdate();
		~Window();
	private:
		bool successfullyCreated = false;

		Window();
		bool IsSuccessfullyCreated() const;
	};
}
#endif
