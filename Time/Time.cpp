// Include files
#include "Time.h"

Time::Time(int hour, int minute, int second)
{
}

Time::Time(const s_hour* my_hours)
{
}

Time::Time(const s_minute* my_minutes)
{
}

Time::Time(const s_second* my_seconds)
{
}

Time::Time(const Time& Time_incoming)
{
}

Time::Time(const Time&& Time_incoming)
{
}

Time::~Time()
{
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
