//Name: Jingtao Cheng
//ID: 940067494
//TimeCounter.cpp
//this file was used to implement functions in time counter class
#include "TimeCounter.h"

#include <stdio.h>
#include <sys/time.h>
//constructor
TimeCounter :: TimeCounter(): current_time(0)
{
	reset();
}
//destructor
TimeCounter :: ~TimeCounter()
{}
//this function was used to reset time to begin a new counter
void TimeCounter::reset()
{
	struct timeval time;
	if(gettimeofday( &time, 0)) return;
	current_time = 1000000 * time.tv_sec + time.tv_usec;
}
//this function was use to get current time in system and return it
double TimeCounter :: getTime()
{
	struct timeval time;
	if (gettimeofday( &time, 0))
	{
		return -1;
	}
	long current_time_ = 1000000 * time.tv_sec + time.tv_usec;
	double sec = (current_time_ - current_time) / 1000000.0;
	if(sec < 0)
	{
		sec += 86400;
	}
	current_time = current_time_;

	return sec;
}
//this function was used to print time
void TimeCounter::printTime()
{
	printf("%lf seconds since working\n", getTime());
}
