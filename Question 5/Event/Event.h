#pragma once
#include "Time.h"
#include "Date.h"

class Event
{
public:
	Event();
	Event(const char* name, const Date& date, const Time& startTime, const Time& endTime);
	
	Event(const char* name, unsigned day, unsigned month, unsigned year,
	      unsigned startTimeHours, unsigned startTimeMins, unsigned startTimeSecs,
	      unsigned endTimeHours,   unsigned endTimeMins,   unsigned endTimeSecs);
	
	const char* getName() const;
	const Date& getDate() const;
	const Time& getStartTime() const;
	const Time& getEndTime() const;
private:
	char _name[21];
	Date _date;
	Time _startTime;
	Time _endTime;

	void setName(const char* str);
	void validateTimes();
};
