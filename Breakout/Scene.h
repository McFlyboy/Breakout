#ifndef SCENE_H
#define SCENE_H

#include "Window.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Ball.h"

namespace breakout
{
	class Scene
	{
	public:
		Scene();
		bool IsSuccessfullyCreated() const;
		void Update(float deltaTime);
		void Render();
		~Scene();
	private:
		bool successfullyCreated = false;
		GameObject* player = nullptr;
		Ball* ball = nullptr;
		GameObject* board = nullptr;

		//These are deleted in Game class
		Window* window = nullptr;
		InputManager* input = nullptr;
	};
}
#endif
