#include "GameObject.h"
#include "Window.h"
#include <iostream>

using namespace std;

namespace breakout
{
	Vector2f position;
	Vector2f size;
	SDL_Texture* texture = nullptr;
	SDL_Rect* rect = nullptr;

	GameObject::GameObject(Vector2f position, const char* pictureFilename)
	{
		breakout::position = position;
		SDL_Surface* surface = SDL_LoadBMP(pictureFilename);
		if (surface == nullptr)
		{
			cerr << "Failed to load image: " << SDL_GetError() << endl;
			return;
		}
		texture = Window::GetInstance()->CreateTextureFromSurface(surface);
		rect = new SDL_Rect();
		rect->x = 0;
		rect->y = 0;
		rect->w = surface->w;
		rect->h = surface->h;
		size.x = static_cast<float>(surface->w);
		size.y = static_cast<float>(surface->h);
		SDL_FreeSurface(surface);
	}
	bool GameObject::IsSuccessfullyCreated() const
	{
		return texture != nullptr && rect != nullptr;
	}
	Vector2f GameObject::GetPosition() const
	{
		return position;
	}
	void GameObject::SetPosition(Vector2f position)
	{
		breakout::position = position;
		rect->x = static_cast<int>(position.x);
		//Flips y-axis on screen. Origo is in the lower left corner
		rect->y = Window::GetInstance()->GetHeight() - static_cast<int>(size.y + position.y);
	}
	void GameObject::Move(const Vector2f movement)
	{
		SetPosition(position + movement);
	}
	Vector2f GameObject::GetSize() const
	{
		return size;
	}
	void GameObject::SetSize(Vector2f size)
	{
		breakout::size = size;
		rect->w = static_cast<int>(size.x);
		rect->h = static_cast<int>(size.y);
	}
	SDL_Texture* GameObject::GetTexture() const
	{
		return texture;
	}
	const SDL_Rect* GameObject::GetRect() const
	{
		return rect;
	}
	GameObject::~GameObject()
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		delete rect;
		rect = nullptr;
	}
}
