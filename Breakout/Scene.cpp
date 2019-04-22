#include "Scene.h"
#include "Vector2f.h"
#include "AABB.h"

namespace breakout
{
	Scene::Scene()
	{
		window = Window::GetInstance();
		input = InputManager::GetInstance();
		player = new GameObject(Vector2f(), "textures/picture.bmp");
		if (!player->IsSuccessfullyCreated())
		{
			return;
		}
		board = new GameObject(Vector2f(), "textures/background.bmp");
		if (!board->IsSuccessfullyCreated())
		{
			return;
		}
		successfullyCreated = true;
		board->SetSize(Vector2f(static_cast<float>(window->GetWidth()), static_cast<float>(window->GetHeight())));
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
		Vector2f playerPos = player->GetPosition();
		if (playerPos.x < 0.0f)
		{
			playerPos.x = 0.0f;
		}
		else if (playerPos.x + player->GetSize().x > board->GetSize().x)
		{
			playerPos.x = board->GetSize().x - player->GetSize().x;
		}
		player->SetPosition(playerPos);
	}
	void Scene::Render()
	{
		window->RenderObject(board);
		window->RenderObject(player);
	}
	Scene::~Scene()
	{
		delete player;
		player = nullptr;
		delete board;
		board = nullptr;
	}
}
