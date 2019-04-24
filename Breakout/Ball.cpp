#include "Ball.h"

namespace breakout
{
	Ball::Ball(const char* pictureFilename, Vector2f position) : GameObject(pictureFilename, position)
	{
		ResetVelocity();
	}
	void Ball::UpdateMovement(float deltaTime)
	{
		Move(velocity * deltaTime);
	}
	void Ball::FlipXVelocity()
	{
		velocity.x *= -1.0f;
	}
	void Ball::FlipYVelocity()
	{
		velocity.y *= -1.0f;
	}
	void Ball::ResetVelocity()
	{
		velocity = Vector2f(1.0f, 1.0f) * 0.1f;
	}
	Ball::~Ball()
	{
		
	}
}
