#include "Scene.h"
#include "Vector2f.h"
#include "AABB.h"

namespace breakout
{
	Scene::Scene()
	{
		window = Window::GetInstance();
		input = InputManager::GetInstance();
		player = new GameObject("textures/player.bmp");
		if (!player->IsSuccessfullyCreated())
		{
			return;
		}
		ball = new Ball("textures/ball.bmp");
		if (!ball->IsSuccessfullyCreated())
		{
			return;
		}

		//background.bmp's resolution should always be 1/4 of the window's size
		board = new GameObject("textures/background.bmp");

		if (!board->IsSuccessfullyCreated())
		{
			return;
		}
		successfullyCreated = true;
		player->SetPosition(Vector2f((board->GetSize().x - player->GetSize().x) / 2.0f, 20.0f));
	}
	bool Scene::IsSuccessfullyCreated() const
	{
		return successfullyCreated;
	}
	void Scene::Update(float deltaTime)
	{
		int dx, dy;
		input->GetMouseDelta(dx, dy);
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
		ball->UpdateMovement(deltaTime);
	}
	void Scene::Render()
	{
		window->RenderObject(board);
		window->RenderObject(player);
		window->RenderObject(ball);
	}
	Scene::~Scene()
	{
		delete player;
		player = nullptr;
		delete ball;
		ball = nullptr;
		delete board;
		board = nullptr;
	}
}
