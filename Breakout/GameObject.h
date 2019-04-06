#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Vector2f.h"
#include <SDL.h>

namespace breakout
{
	class GameObject
	{
	public:
		GameObject(Vector2f position, const char* pictureFilename);
		bool IsSuccessfullyCreated() const;
		Vector2f GetPosition() const;
		void SetPosition(Vector2f position);
		void Move(const Vector2f movement);
		Vector2f GetSize() const;
		void SetSize(Vector2f size);
		SDL_Texture* GetTexture() const;
		const SDL_Rect* GetRect() const;
		~GameObject();
	};
}
#endif
