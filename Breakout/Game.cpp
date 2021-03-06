#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "InputManager.h"
#include "Time.h"
#include "Scene.h"

using namespace std;

namespace breakout
{
	class Game
	{
	private:
		Window* window = nullptr;
		InputManager* input = nullptr;
		Time* time = nullptr;
		Scene* scene = nullptr;

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
			if (!input->CaptureMouse(true))
			{
				cout << "Mouse capture not supported!" << endl << SDL_GetError() << endl;
			}
			time = Time::GetInstance();

			//Gameplay happens in Scene
			scene = new Scene();

			if (!scene->IsSuccessfullyCreated())
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
			bool keepRunning = scene->Update(deltaTime);
			time->AddUpdateCount();
			return keepRunning;
		}
		void Render()
		{
			scene->Render();
			window->RenderUpdate();
			time->AddFrameCount();
		}
	public:
		bool Run()
		{
			bool runSuccess = Start();
			if (!runSuccess)
			{
				return runSuccess;
			}
			double targetFrameTime = 1000.0 / static_cast<double>(window->GetMonitorRefreshRate());
			double renderTimeRemaining = 0.0;
			bool renderReady = false;
			bool running = true;
			cout << "Game started!\n--WELCOME TO BREAKOUT--\n" << endl;
			time->GetDeltaTime();
			while (running)
			{
				double deltaTime = time->GetDeltaTime();
				running = Update(static_cast<float>(deltaTime));
				if (renderTimeRemaining <= 0.0)
				{
					renderReady = true;
					renderTimeRemaining += targetFrameTime;
				}
				renderTimeRemaining -= deltaTime;
				if (renderReady)
				{
					Render();
					renderReady = false;
				}
				if (time->UpdatePerSecCounters())
				{
					cout << "FPS: " << time->GetFPS() << " - UPS: " << time->GetUPS() << endl;
				}
			}
			cout << "\n--GAME OVER--\nThanks for playing!" << endl;
			return runSuccess;
		}
		~Game()
		{
			delete scene;
			scene = nullptr;
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
