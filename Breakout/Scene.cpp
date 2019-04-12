#include "Scene.h"
#include "Window.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Vector2f.h"

namespace breakout
{
	//These are deleted in Game class
	Window* window = nullptr;
	InputManager* input = nullptr;

	GameObject* square = nullptr;

	Scene::Scene()
	{
		window = Window::GetInstance();
		input = InputManager::GetInstance();
		square = new GameObject(Vector2f(), "picture.bmp");
		if (!square->IsSuccessfullyCreated())
		{
			return;
		}
		successfullyCreated = true;
	}
	bool Scene::IsSuccessfullyCreated() const
	{
		return successfullyCreated;
	}
	void Scene::Update(float deltaTime)
	{
		Vector2f movement;
		float speed = 0.5f * deltaTime;
		if (input->KeyDown(SDL_SCANCODE_LEFT) || input->KeyStillDown(SDL_SCANCODE_LEFT))
		{
			movement.x -= speed;
		}
		if (input->KeyDown(SDL_SCANCODE_RIGHT) || input->KeyStillDown(SDL_SCANCODE_RIGHT))
		{
			movement.x += speed;
		}
		if (input->KeyDown(SDL_SCANCODE_UP) || input->KeyStillDown(SDL_SCANCODE_UP))
		{
			movement.y += speed;
		}
		if (input->KeyDown(SDL_SCANCODE_DOWN) || input->KeyStillDown(SDL_SCANCODE_DOWN))
		{
			movement.y -= speed;
		}
		square->Move(movement);
	}
	void Scene::Render()
	{
		window->RenderObject(square);
	}
	Scene::~Scene()
	{
		delete square;
		square = nullptr;
	}
}
