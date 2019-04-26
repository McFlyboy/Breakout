#include "Scene.h"
#include "Vector2f.h"
#include "AABB.h"
#include <iostream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

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

		//background.bmp's resolution should be 1/4 of the window's size, as it will be scaled up later
		board = new GameObject("textures/background.bmp");

		if (!board->IsSuccessfullyCreated())
		{
			return;
		}
		blocks = new GameObject*[blockCount];
		unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
		default_random_engine generator(seed);
		uniform_int_distribution<int> distribution(0, 2);
		for (int i = 0; i < blockCount; i++)
		{
			string filename;
			int blockColorIndex = distribution(generator);
			switch (blockColorIndex)
			{
			case 1:
				filename = "textures/block-red.bmp";
				break;
			case 2:
				filename = "textures/block-magenta.bmp";
				break;
			default:
				filename = "textures/block-blue.bmp";
				break;
			}
			GameObject** block = blocks + i;
			*block = new GameObject(filename.c_str());
			if (!(*block)->IsSuccessfullyCreated())
			{
				return;
			}
		}
		Vector2f blockSize = (*blocks)->GetSize();
		float spacing = 4.0f;
		for (int i = 0; i < blockCount; i++)
		{
			(*(blocks + i))->SetPosition(Vector2f(100 + (blockSize.x + spacing) * static_cast<float>(i % 8), 500 - (blockSize.y + spacing) * static_cast<float>(i / 8)));
		}
		successfullyCreated = true;
		player->SetPosition(Vector2f((board->GetSize().x - player->GetSize().x) / 2.0f, 20.0f));
		ball->SetPosition(Vector2f(100.0f, 100.0f));
	}
	bool Scene::IsSuccessfullyCreated() const
	{
		return successfullyCreated;
	}
	bool Scene::Update(float deltaTime)
	{
		//Grab desired player-movement from InputHandler
		int dx, dy;
		input->GetMouseDelta(dx, dy);
		Vector2f desiredMovement = Vector2f(static_cast<float>(dx) * 0.75f);

		//Move player and make sure it stays on the board
		player->Move(desiredMovement);
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

		//Player pushes the ball if player crashes into the ball
		if (AABB::IsIntersecting(player, ball))
		{
			ball->Move(desiredMovement);
		}

		//The ball moves and checks if it needs to ricochet to avoid collision
		handleBallToObjectCollision(ball, player, deltaTime);
		for (int i = 0; i < blockCount; i++)
		{
			GameObject** block = blocks + i;
			if (*block != nullptr)
			{
				if (handleBallToObjectCollision(ball, *block, deltaTime))
				{
					delete *block;
					*block = nullptr;
					blocksAlive--;
					if (blocksAlive == 0)
					{
						cout << "\n\nCongratulations! You won!\nPress Escape to exit.\n" << endl;
					}
				}
			}
		}
		ball->UpdateMovement(deltaTime);

		//Pushes the ball back and ricochets it back into the board if it gets outside from one of the sides or at the top of the board.
		//Also makes sure that player is pushed back as well to give space for the ball, in case it was trying to push the ball outside of the board
		Vector2f ballPos = ball->GetPosition();
		if (ballPos.x < 0.0f)
		{
			float correction = -ballPos.x;
			ballPos.x = 0.0f;
			ball->FlipXVelocity();
			player->Move(Vector2f(correction));
		}
		else if (ballPos.x + ball->GetSize().x > board->GetSize().x)
		{
			float correction = board->GetSize().x - (ballPos.x + ball->GetSize().x);
			ballPos.x = board->GetSize().x - ball->GetSize().x;
			ball->FlipXVelocity();
			player->Move(Vector2f(correction));
		}
		if (ballPos.y + ball->GetSize().y > board->GetSize().y)
		{
			ballPos.y = board->GetSize().y - ball->GetSize().y;
			ball->FlipYVelocity();
		}
		else if (ballPos.y < -200)
		{
			return false;
		}
		ball->SetPosition(ballPos);
		return true;
	}
	void Scene::Render()
	{
		window->RenderObject(board);
		window->RenderObject(player);
		for (int i = 0; i < blockCount; i++)
		{
			GameObject* block = *(blocks + i);
			if (block != nullptr)
			{
				window->RenderObject(block);
			}
		}
		window->RenderObject(ball);
	}
	bool Scene::handleBallToObjectCollision(Ball* ball, GameObject* obj, const float deltaTime)
	{
		if (AABB::WillIntersect(ball, obj, deltaTime))
		{
			bool xIntersect, yIntersect;
			if (xIntersect = AABB::WillXIntersect(ball, obj, deltaTime))
			{
				ball->FlipXVelocity();
			}
			if (yIntersect = AABB::WillYIntersect(ball, obj, deltaTime))
			{
				ball->FlipYVelocity();
			}
			if (!xIntersect && !yIntersect)
			{
				ball->FlipXVelocity();
				ball->FlipYVelocity();
			}
			return true;
		}
		return false;
	}
	Scene::~Scene()
	{
		delete player;
		player = nullptr;
		delete ball;
		ball = nullptr;
		for (int i = 0; i < blockCount; i++)
		{
			GameObject** block = blocks + i;
			delete *block;
			*block = nullptr;
		}
		delete[] blocks;
		blocks = nullptr;
		delete board;
		board = nullptr;
	}
}
