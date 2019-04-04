#include "GameObject.h"
#include "Window.h"
#include <iostream>

using namespace std;

namespace breakout
{
	Vector2f position;
	SDL_Texture* texture = nullptr;
	SDL_Rect* coords = nullptr;

	GameObject::GameObject(const char* pictureFilename)
	{
		SDL_Surface* surface = SDL_LoadBMP(pictureFilename);
		if (surface == nullptr)
		{
			cerr << "Failed to load image: " << SDL_GetError() << endl;
			return;
		}
		texture = Window::GetInstance()->CreateTextureFromSurface(surface);
		coords = new SDL_Rect();
		coords->x = 0;
		coords->y = 0;
		coords->w = surface->w;
		coords->h = surface->h;
		SDL_FreeSurface(surface);
	}
	bool GameObject::IsSuccessfullyCreated() const
	{
		return texture != nullptr && coords != nullptr;
	}
	SDL_Texture* GameObject::GetTexture() const
	{
		return texture;
	}
	const SDL_Rect* GameObject::GetCoords() const
	{
		return coords;
	}
	void GameObject::Move(const Vector2f movement)
	{
		position += movement;
		coords->x = static_cast<int>(position.x);
		coords->y = static_cast<int>(position.y);
	}
	GameObject::~GameObject()
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		delete coords;
		coords = nullptr;
	}
}
