#include "Timer.h"

using namespace swd;

Timer::Timer(void):_step(0),_curTime(0)
{
}

Timer::~Timer(void)
{
}

void Timer::init(TimeConfig config){
	_step = config.step;
	_curTime = config.curTime;
}