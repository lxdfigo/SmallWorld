#pragma once

namespace swd{
	class Time
	{
	public:
		Time(void);
		~Time(void);

		void advance(){ _curTime += _step;}
		double step(){return _step;}
	private:
		double _step;
		double _curTime;
	};
}