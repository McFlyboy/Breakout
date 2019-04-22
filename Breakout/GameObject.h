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

		/**
		*
		* Convenience function for moving the position
		*
		*/
		void Move(const Vector2f movement);

		Vector2f GetSize() const;
		void SetSize(Vector2f size);
		SDL_Texture* GetTexture() const;
		~GameObject();
	private:
		Vector2f position;
		Vector2f size;
		SDL_Texture* texture = nullptr;
	};
}
#endif
