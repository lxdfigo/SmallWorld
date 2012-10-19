#pragma once

namespace swd{
	struct TimeConfig{
		double curTime;
		double step;
	};
	class Timer
	{
	public:
		Timer(void);
		~Timer(void);

		void init(TimeConfig config);
		void advance(){ _curTime += _step;}
		double step(){return _step;}
	private:
		double _step;
		double _curTime;
	};
}