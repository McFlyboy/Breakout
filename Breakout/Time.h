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
		Time();
	};
}
#endif
