#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <SDL.h>

namespace breakout
{
	class InputManager
	{
	public:
		static InputManager* GetInstance();
		bool Update();

		//Keyboard
		bool KeyDown(int iKeyIndex)
		{
			return CurrentKeyDown(iKeyIndex) && !OldKeyDown(iKeyIndex);
		}
		bool KeyStillDown(int iKeyIndex)
		{
			return CurrentKeyDown(iKeyIndex) && OldKeyDown(iKeyIndex);
		}
		bool KeyUp(int iKeyIndex)
		{
			return !CurrentKeyDown(iKeyIndex) && OldKeyDown(iKeyIndex);
		}
		bool KeyStillUp(int iKeyIndex)
		{
			return !CurrentKeyDown(iKeyIndex) && !OldKeyDown(iKeyIndex);
		}

		//Mouse
		bool MouseDown(int iButton)
		{
			return CurrentMouseDown(iButton) && !OldMouseDown(iButton);
		}
		bool MouseStillDown(int iButton)
		{
			return CurrentMouseDown(iButton) && OldMouseDown(iButton);
		}
		bool MouseUp(int iButton)
		{
			return !CurrentMouseDown(iButton) && OldMouseDown(iButton);
		}
		bool MouseStillUp(int iButton)
		{
			return !CurrentMouseDown(iButton) && !OldMouseDown(iButton);
		}
		void GetMouseDelta(int* deltaX, int* deltaY);
		bool CaptureMouse(bool capture);

		~InputManager();
	private:
		InputManager();
		bool CurrentKeyDown(int iKeyIndex);
		bool OldKeyDown(int iKeyIndex);
		bool CurrentMouseDown(int iKeyIndex);
		bool OldMouseDown(int iKeyIndex);
	};
}
#endif
