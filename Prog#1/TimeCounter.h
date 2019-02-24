//Name: Jingtao Cheng
//ID: 940067494
//TimeCounter.h
//this function was used to declare time counter class for count time function
#ifndef TIME_COUNTER
#define TIME_COUNTER
//Time counter class was used to get time in system to help manager fire surpression tools working time
class TimeCounter
{
private:
	long current_time;

public:
	TimeCounter();//constructor
    ~TimeCounter();//desctructor
	void reset();//this function was used to reset time to begin a new counter
	double getTime();//this function was use to get current time in system and return it
	void printTime();//this function was used to print time
};

#endif
