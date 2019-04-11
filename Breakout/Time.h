#ifndef TIME_H
#define TIME_H
namespace breakout
{
	class Time
	{
	public:
		static Time* GetInstance();

		double GetTime() const;
		float GetDeltaTime();
		int GetFPS() const;
		bool UpdateFPS();
		~Time();
	private:
		Time();
	};
}
#endif
