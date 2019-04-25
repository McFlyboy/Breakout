#include "AABB.h"
#include "Vector2f.h"

namespace breakout
{
	bool AABB::IsIntersecting(const Vector2f pos1, const Vector2f size1, const Vector2f pos2, const Vector2f size2)
	{
		Vector2f sizePos1 = pos1 + size1;
		Vector2f sizePos2 = pos2 + size2;
		return pos1.x < sizePos2.x &&
			pos1.y < sizePos2.y &&
			sizePos1.x > pos2.x &&
			sizePos1.y > pos2.y;
	}
	bool AABB::IsIntersecting(const GameObject* obj1, const GameObject* obj2)
	{
		return IsIntersecting(obj1->GetPosition(), obj1->GetSize(), obj2->GetPosition(), obj2->GetSize());
	}
	bool AABB::WillIntersect(const Ball* ball, const GameObject* obj, const float deltaTime)
	{
		return IsIntersecting(ball->GetPosition() + (ball->GetVelocity() * deltaTime), ball->GetSize(), obj->GetPosition(), obj->GetSize());
	}
	bool AABB::WillXIntersect(const Ball* ball, const GameObject* obj, const float deltaTime)
	{
		return IsIntersecting(ball->GetPosition() + Vector2f(ball->GetVelocity().x * deltaTime), ball->GetSize(), obj->GetPosition(), obj->GetSize());
	}
	bool AABB::WillYIntersect(const Ball* ball, const GameObject* obj, const float deltaTime)
	{
		return IsIntersecting(ball->GetPosition() + Vector2f(0.0f, ball->GetVelocity().y * deltaTime), ball->GetSize(), obj->GetPosition(), obj->GetSize());
	}
}
