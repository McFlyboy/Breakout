#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Vector2f.h"

namespace breakout
{
	class Ball : public GameObject
	{
	public:
		Ball(const char* pictureFilename, Vector2f position = Vector2f());
		Vector2f GetVelocity() const;
		void UpdateMovement(float deltaTime);
		void UpdateXMovement(float deltaTime);
		void UpdateYMovement(float deltaTime);
		void FlipXVelocity();
		void FlipYVelocity();
		void ResetVelocity();
		~Ball();
	private:
		Vector2f velocity;
	};
}
#endif
