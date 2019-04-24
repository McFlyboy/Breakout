#include "AABB.h"
#include "Vector2f.h"

namespace breakout
{
	bool AABB::IsIntersecting(const GameObject& obj1, const GameObject& obj2)
	{
		Vector2f obj1Corner1 = obj1.GetPosition();
		Vector2f obj1Corner2 = obj1Corner1 + obj1.GetSize();
		Vector2f obj2Corner1 = obj2.GetPosition();
		Vector2f obj2Corner2 = obj2Corner1 + obj2.GetSize();
		return obj1Corner1.x < obj2Corner2.x &&
			obj1Corner1.y < obj2Corner2.y &&
			obj1Corner2.x > obj2Corner1.x &&
			obj1Corner2.y > obj2Corner1.y;
	}
}
