#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
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
		void Move(const float x, const float y);
		~GameObject();
	};
}
#endif
