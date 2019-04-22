#ifndef AABB_H
#define AABB_H

#include "GameObject.h"

namespace breakout
{
	namespace AABB
	{
		bool IsIntersecting(const GameObject* const obj1, const GameObject* const obj2);
	};
}
#endif
