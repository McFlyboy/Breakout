#include "InputManager.h"
#include <memory>
#include <SDL.h>

using namespace std;

namespace breakout
{
	InputManager* InputManager::instance = nullptr;

	const Uint8* keys = nullptr;
	unique_ptr<Uint8> oldKeys;
	int keyCount;
	int mouseX;
	int mouseY;
	Uint8 buttons;
	Uint8 oldButtons;

	InputManager::InputManager()
	{
		keys = SDL_GetKeyboardState(&keyCount);
		oldKeys = unique_ptr<Uint8>(new Uint8[keyCount]);
	}
	InputManager* InputManager::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new InputManager();
		}
		return instance;
	}
	bool InputManager::CurrentKeyDown(int iKeyIndex)
	{
		return keys[iKeyIndex] != 0;
	}
	bool InputManager::OldKeyDown(int iKeyIndex)
	{
		return oldKeys.get()[iKeyIndex] != 0;
	}
	bool InputManager::CurrentMouseDown(int iKeyIndex)
	{
		return buttons == SDL_BUTTON(iKeyIndex);
	}
	bool InputManager::OldMouseDown(int iKeyIndex)
	{
		return oldButtons == SDL_BUTTON(iKeyIndex);
	}
	void InputManager::GetMouseDelta(int& deltaX, int& deltaY)
	{
		deltaX = mouseX;

		//Flips y-axis
		deltaY = -mouseY;
	}
	bool InputManager::CaptureMouse(bool capture)
	{
		return SDL_SetRelativeMouseMode(capture ? SDL_TRUE : SDL_FALSE) == 0;
	}
	bool InputManager::Update()
	{
		oldButtons = buttons;
		memcpy(oldKeys.get(), keys, keyCount * sizeof(Uint8));
		SDL_PumpEvents();
		if (SDL_HasEvent(SDL_QUIT))
		{
			return false;
		}
		buttons = SDL_GetRelativeMouseState(&mouseX, &mouseY);
		return true;
	}
	InputManager::~InputManager()
	{
		keys = nullptr;
	}
}
