#ifndef AABB_H
#define AABB_H

#include "GameObject.h"
#include "Ball.h"

namespace breakout
{
	namespace AABB
	{
		bool IsIntersecting(const Vector2f pos1, const Vector2f size1, const Vector2f pos2, const Vector2f size2);
		bool IsIntersecting(const GameObject* obj1, const GameObject* obj2);
		bool WillIntersect(const Ball* ball, const GameObject* obj, const float deltaTime);
		bool WillXIntersect(const Ball* ball, const GameObject* obj, const float deltaTime);
		bool WillYIntersect(const Ball* ball, const GameObject* obj, const float deltaTime);
	};
}
#endif
