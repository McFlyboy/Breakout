#include "GameObject.h"
#include "Window.h"
#include <iostream>

using namespace std;

namespace breakout
{
	GameObject::GameObject(const char* pictureFilename, Vector2f position)
	{
		this->position = position;
		SDL_Surface* surface = SDL_LoadBMP(pictureFilename);
		if (surface == nullptr)
		{
			cerr << "Failed to load image: " << SDL_GetError() << endl;
			return;
		}
		texture = Window::GetInstance()->CreateTextureFromSurface(surface);

		//Size is multiplied by 4 to scale up and fit the game's pixel-art style
		size.x = static_cast<float>(surface->w * 4);
		size.y = static_cast<float>(surface->h * 4);

		SDL_FreeSurface(surface);
	}
	bool GameObject::IsSuccessfullyCreated() const
	{
		return texture != nullptr;
	}
	Vector2f GameObject::GetPosition() const
	{
		return position;
	}
	void GameObject::SetPosition(Vector2f position)
	{
		this->position = position;
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
		this->size = size;
	}
	SDL_Texture* GameObject::GetTexture() const
	{
		return texture;
	}
	GameObject::~GameObject()
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}
