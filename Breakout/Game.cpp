#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "InputManager.h"
#include "Time.h"
#include "GameObject.h"
#include "Vector2f.h"

using namespace std;

namespace breakout
{
	class Game
	{
	private:
		Window* window = nullptr;
		InputManager* input = nullptr;
		Time* time = nullptr;
		GameObject* square = nullptr;

		bool Start()
		{
			window = Window::GetInstance();
			if (window == nullptr)
			{
				return false;
			}
			window->SetDrawColor(0, 0, 0);
			window->Clear();
			input = InputManager::GetInstance();
			time = Time::GetInstance();
			square = new GameObject(Vector2f(), "picture.bmp");
			if (!square->IsSuccessfullyCreated())
			{
				return false;
			}
			return true;
		}
		bool Update(float deltaTime)
		{
			if (!input->Update() || input->KeyDown(SDL_SCANCODE_ESCAPE))
			{
				return false;
			}
			bool left = input->KeyDown(SDL_SCANCODE_LEFT);
			bool right = input->KeyDown(SDL_SCANCODE_RIGHT);
			bool up = input->KeyDown(SDL_SCANCODE_UP);
			bool down = input->KeyDown(SDL_SCANCODE_DOWN);
			/*if (left)
			{
				cout << "Left key pressed" << endl;
			}
			if (right)
			{
				cout << "Right key pressed" << endl;
			}
			if (up)
			{
				cout << "Up key pressed" << endl;
			}
			if (down)
			{
				cout << "Down key pressed" << endl;
			}*/
			Vector2f movement;
			float speed = 0.5f * deltaTime;
			if (left || input->KeyStillDown(SDL_SCANCODE_LEFT))
			{
				movement.x -= speed;
			}
			if (left || input->KeyStillDown(SDL_SCANCODE_RIGHT))
			{
				movement.x += speed;
			}
			if (left || input->KeyStillDown(SDL_SCANCODE_UP))
			{
				movement.y += speed;
			}
			if (left || input->KeyStillDown(SDL_SCANCODE_DOWN))
			{
				movement.y -= speed;
			}
			square->Move(movement);
			return true;
		}
		void Render()
		{
			window->RenderObject(square);
			window->RenderUpdate();
		}
	public:
		bool Run()
		{
			bool runSuccess = Start();
			if (!runSuccess)
			{
				return runSuccess;
			}
			bool running = true;
			while (running)
			{
				running = Update(time->GetDeltaTime());
				Render();
				if (time->UpdateFPS())
				{
					cout << "FPS: " << time->GetFPS() << endl;
				}
			}
			return runSuccess;
		}
		~Game()
		{
			delete square;
			square = nullptr;
			delete time;
			time = nullptr;
			delete input;
			input = nullptr;
			delete window;
			window = nullptr;
			SDL_Quit();
		}
	};
}
int main(int argc, char* argv[])
{
	return breakout::Game::Game().Run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
