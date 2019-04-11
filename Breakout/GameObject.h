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
		Vector2f* GetPosition() const;
		void SetPosition(Vector2f position);
		/**
		*
		* Convenience function for moving the position statically
		*
		*/
		void Move(const Vector2f movement);

		Vector2f* GetSize() const;
		void SetSize(Vector2f size);
		SDL_Texture* GetTexture() const;
		const SDL_Rect* GetRect() const;
		/**
		*
		* Prepares the internal SDL_Rect before rendering.
		* This function does not need to be called manually, as it gets called by Window::RenderObject(GameObject* object)
		*
		*/
		void PrepareRect();

		~GameObject();
	};
}
#endif
