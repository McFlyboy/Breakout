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

	GameObject* player = nullptr;

	Scene::Scene()
	{
		window = Window::GetInstance();
		input = InputManager::GetInstance();
		player = new GameObject(Vector2f(), "picture.bmp");
		if (!player->IsSuccessfullyCreated())
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
		int dx, dy;
		input->GetMouseDelta(&dx, &dy);
		player->Move(Vector2f(static_cast<float>(dx) * 0.75f, 0.0f));
	}
	void Scene::Render()
	{
		window->RenderObject(player);
	}
	Scene::~Scene()
	{
		delete player;
		player = nullptr;
	}
}
