#ifndef SCENE_H
#define SCENE_H

namespace breakout
{
	class Scene
	{
	public:
		Scene();
		bool IsSuccessfullyCreated() const;
		void Update(float deltaTime);
		void Render();
		~Scene();
	private:
		bool successfullyCreated = false;
	};
}
#endif
