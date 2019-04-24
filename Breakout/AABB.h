#ifndef AABB_H
#define AABB_H

#include "GameObject.h"

namespace breakout
{
	namespace AABB
	{
		bool IsIntersecting(const GameObject& obj1, const GameObject& obj2);
	};
}
#endif
