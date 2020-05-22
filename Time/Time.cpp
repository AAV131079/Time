// Include files
#include "Time.h"

// Macroses
#define DAY 24
#define HALF_DAY 12
#define HOUR 60
#define MINUTE 60
#define AM " a.m."
#define PM " p.m."

// Namespace std
using namespace std;

// Constructor (hour + minutes + stcond (default = 0))
Time :: Time(int hour, int minute, int second)
{
	// Check hours
	if (hour >= 0 && hour < DAY)
	{
		// Set hours
		this -> SetHour(hour);
	}
	// Check minutes
	if (minute >= 0 && minute < HOUR)
	{
		// Set minutes
		this -> SetMinute(minute);
	}
	// Check second
	if (second >= 0 && second < MINUTE)
	{
		// Set seconds
		this -> SetSecond(second);
	}
	// Type clock
	this -> SetTypeClock(1);
	// Midday and midnight designations
	this -> SetAM_PM(0);
	// Type time
	this -> SetTypeTime(1);
}

// Constructor (hour)
Time :: Time(const s_hour * my_hours)
{
	// Set hours
	this -> SetHour(my_hours -> hour);
	// Set minutes
	this -> SetMinute(0);
	// Set seconds
	this -> SetSecond(0);
	// Type clock
	this -> SetTypeClock(1);
	// Midday and midnight designations
	this -> SetAM_PM(0);
	// Type time
	this -> SetTypeTime(1);
}

// Constructor (minutes)
Time :: Time(const s_minute * my_minutes)
{
	// Variables
	int hours{};
	// Check minutes
	if (my_minutes -> minute < HOUR)
	{
		// Set minutes
		this -> SetMinute(my_minutes -> minute);
		// Set hours
		this -> SetHour(0);
	}
	else if (my_minutes -> minute >= HOUR)
	{
		// How many hours
		hours = (int)(my_minutes -> minute / HOUR);
		// Set minutes
		this -> SetMinute(my_minutes -> minute - HOUR * hours);
		// Set hours
		this -> SetHour(hours);
	}
	// Set seconds
	this -> SetSecond(0);
	// Type clock
	this -> SetTypeClock(1);
	// Midday and midnight designations
	this -> SetAM_PM(0);
	// Type time
	this -> SetTypeTime(1);
}

// Constructor (second)
Time :: Time(const s_second * my_seconds)
{
	// Variables
	int hours{}, minutes{};
	// Check seconds
	if (my_seconds -> second < MINUTE)
	{
		// Set seconds
		this -> SetSecond(my_seconds -> second);
		// Set minutes
		this -> SetMinute(0);
		// Set hours
		this -> SetHour(0);
	}
	else if (my_seconds -> second >= MINUTE)
	{
		// How many minutes
		minutes = (int)(my_seconds -> second / MINUTE);
		// Seconds
		this -> SetSecond(my_seconds -> second - MINUTE * minutes);
		// Check minutes
		if (minutes < HOUR)
		{
			// Set minutes
			this -> SetMinute(minutes);
			// Set hours
			this -> SetHour(0);
		}
		else if (minutes >= HOUR)
		{
			// How many hours
			hours = (int)(minutes / HOUR);
			// Set minutes
			this -> SetMinute(minutes - hours * HOUR);
			// Set hours
			this -> SetHour(hours);
		}
	}
	// Type clock
	this -> SetTypeClock(1);
	// Midday and midnight designations
	this -> SetAM_PM(0);
	// Type time
	this -> SetTypeTime(1);
}

// Copy constructor
Time :: Time(const Time & Time_incoming)
{
	// Hour
	this -> SetHour(Time_incoming._hour);
	// Minute
	this -> SetMinute(Time_incoming._minute);
	// Second
	this -> SetSecond(Time_incoming._second);
	// Type clock
	this -> SetTypeClock(Time_incoming._type_clock);
	// Midday and midnight designations
	this -> SetAM_PM(Time_incoming._am_pm);
	// Type time
	this -> SetTypeTime(Time_incoming._type_time);
}

// Transfer constructor
Time :: Time(const Time && Time_incoming)
{
	// Hour
	this -> SetHour(Time_incoming._hour);
	// Minute
	this -> SetMinute(Time_incoming._minute);
	// Second
	this -> SetSecond(Time_incoming._second);
	// Type clock
	this -> SetTypeClock(Time_incoming._type_clock);
	// Midday and midnight designations
	this -> SetAM_PM(Time_incoming._am_pm);
	// Type time
	this -> SetTypeTime(Time_incoming._type_time);
	// Destruct incoming object
	Time_incoming.~Time();
}

// Destructor
Time :: ~Time()
{
	// Hour
	this -> _hour = 0;
	// Minute
	this -> _minute = 0;
	// Second
	this -> _second = 0;
	// Type clock
	this -> _type_clock = 0;
	// Midday and midnight designations
	this -> _am_pm = 0;
	// Type time
	this -> _type_time = 0;
}


Time& Time::operator=(const Time& Time_incoming)
{
	// TODO: вставьте здесь оператор return
}

Time& Time::operator=(const Time&& Time_incoming)
{
	// TODO: вставьте здесь оператор return
}

Time Time::operator+(Time& Time_incoming)
{
	return Time();
}

Time Time::operator+(const s_hour* my_hours)
{
	return Time();
}

Time Time::operator+(const s_minute* my_minutes)
{
	return Time();
}

Time Time::operator+(const s_second* my_seconds)
{
	return Time();
}

Time Time::operator-(Time& Time_incoming)
{
	return Time();
}

Time Time::operator-(const s_hour* my_hours)
{
	return Time();
}

Time Time::operator-(const s_minute* my_minutes)
{
	return Time();
}

Time Time::operator-(const s_second* my_seconds)
{
	return Time();
}

void Time::SetHour(int hour)
{
}

void Time::SetMinute(int minute)
{
}

void Time::SetSecond(int second)
{
}

void Time::SetTypeClock(int typeclock)
{
}

void Time::SetAM_PM(int am_pm)
{
}

void Time::SetTypeTime(int type_time)
{
}

int Time::GetHour()
{
	return 0;
}

int Time::GetMinute()
{
	return 0;
}

int Time::GetSecond()
{
	return 0;
}

int Time::GetTypeClock()
{
	return 0;
}

int Time::GetAMPM()
{
	return 0;
}

int Time::GetTypeTime()
{
	return 0;
}

void Time::ChangeTimeFormat()
{
}

void Time::ChangeTimeZone(int hour, int minute)
{
}

void Time::ClockChange()
{
}

void Time::InputTime(int hour, int minute, int second)
{
}

void Time::ShowTime()
{
}
