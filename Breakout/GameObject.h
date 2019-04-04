#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Vector2f.h"
#include <SDL.h>

namespace breakout
{
	class GameObject
	{
	public:
		GameObject(const char* pictureFilename);
		bool IsSuccessfullyCreated() const;
		SDL_Texture* GetTexture() const;
		const SDL_Rect* GetCoords() const;
		void Move(const Vector2f movement);
		~GameObject();
	};
}
#endif
