#ifndef TIME_H
#define TIME_H
namespace breakout
{
	class Time
	{
	public:
		static Time* GetInstance();

		double GetTime() const;
		double GetDeltaTime();
		int GetFPS() const;
		int GetUPS() const;
		void AddFrameCount();
		void AddUpdateCount();
		bool UpdatePerSecCounters();
		~Time();
	private:
		static Time* instance;

		double initTime = 0.0;
		double previousUpdateTime = 0.0;
		double previousPerSecTime = 0.0;
		int frames = 0;
		int updates = 0;
		int fps = 0;
		int ups = 0;

		Time();
	};
}
#endif
