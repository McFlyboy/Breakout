#include "Ball.h"

namespace breakout
{
	Ball::Ball(const char* pictureFilename, Vector2f position) : GameObject(pictureFilename, position)
	{
		ResetVelocity();
	}
	Vector2f Ball::GetVelocity() const
	{
		return velocity;
	}
	void Ball::UpdateMovement(float deltaTime)
	{
		Move(velocity * deltaTime);
	}
	void Ball::UpdateXMovement(float deltaTime)
	{
		Move(Vector2f(velocity.x * deltaTime));
	}
	void Ball::UpdateYMovement(float deltaTime)
	{
		Move(Vector2f(velocity.y * deltaTime));
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
		velocity = Vector2f(1.0f, 1.0f) * 0.02f;
	}
	Ball::~Ball()
	{
		
	}
}
