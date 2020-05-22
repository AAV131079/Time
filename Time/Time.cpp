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

// Copy assignment operator overload
Time & Time :: operator = (const Time & Time_incoming)
{
	// Hour
	this->SetHour(Time_incoming._hour);
	// Minute
	this->SetMinute(Time_incoming._minute);
	// Second
	this->SetSecond(Time_incoming._second);
	// Type clock
	this->SetTypeClock(Time_incoming._type_clock);
	// Midday and midnight designations
	this->SetAM_PM(Time_incoming._am_pm);
	// Time comversion
	this->SetTypeTime(Time_incoming._type_time);
	// Function return value
	return *this;
}

// Transfer assignment operator overload
Time & Time ::operator = (const Time && Time_incoming)
{
	// Hour
	this->SetHour(Time_incoming._hour);
	// Minute
	this->SetMinute(Time_incoming._minute);
	// Second
	this->SetSecond(Time_incoming._second);
	// Type clock
	this->SetTypeClock(Time_incoming._type_clock);
	// Midday and midnight designations
	this->SetAM_PM(Time_incoming._am_pm);
	// Time comversion
	this->SetTypeTime(Time_incoming._type_time);
	// Function return value
	return *this;
}

// Overload operator + (object + object)
Time Time :: operator + (Time & Time_incoming)
{
	// Variables
	int days{}, hours{}, minutes{};
	// New time
	Time TemporaryTime;
	// Fold seconds
	if ((this->_second + Time_incoming._second) < MINUTE)
	{
		// Seconds
		TemporaryTime._second = this->_second + Time_incoming._second;
	}
	else if ((this->_second + Time_incoming._second) >= MINUTE)
	{
		// How many minutes
		minutes = (int)((this->_second + Time_incoming._second) / MINUTE);
		// Seconds
		TemporaryTime._second = (this->_second + Time_incoming._second) - MINUTE * minutes;
		// Minutes
		TemporaryTime._minute = minutes;
		// Chech minutes
		if (TemporaryTime._minute >= HOUR)
		{
			// How many hours
			hours = (int)(TemporaryTime._minute / HOUR);
			// MInutes
			TemporaryTime._minute -= HOUR * hours;
			// Hours
			TemporaryTime._hour = hours;
			// Check hours
			if (TemporaryTime._hour >= DAY)
			{
				// How many days
				days = (int)(TemporaryTime._hour / DAY);
				// Hours
				TemporaryTime._hour -= DAY * days;
			}
		}
	}
	// Fold minutes
	if ((this->_minute + Time_incoming._minute + TemporaryTime._minute) < HOUR)
	{
		// Minutes
		TemporaryTime._minute = this->_minute + Time_incoming._minute + TemporaryTime._minute;
	}
	else if ((this->_minute + Time_incoming._minute + TemporaryTime._minute) >= HOUR)
	{
		// How many hours
		hours = (int)((this->_minute + Time_incoming._minute + TemporaryTime._minute) / HOUR);
		// MInutes
		TemporaryTime._minute = this->_minute + Time_incoming._minute + TemporaryTime._minute - HOUR * hours;
		// Hours
		TemporaryTime._hour = hours;
		// Check hours
		if (TemporaryTime._hour >= DAY)
		{
			// How many days
			days = (int)(TemporaryTime._hour / DAY);
			// Hours
			TemporaryTime._hour -= DAY * days;
		}
	}
	// Fold hours
	if ((this->_hour + Time_incoming._hour + TemporaryTime._hour) < DAY)
	{
		// Hours
		TemporaryTime._hour += (this->_hour + Time_incoming._hour);
	}
	else if ((this->_hour + Time_incoming._hour + TemporaryTime._hour) >= DAY)
	{
		// How many days
		days = (int)((this->_hour + Time_incoming._hour + TemporaryTime._hour) / DAY);
		// Hours
		TemporaryTime._hour = (this->_hour + Time_incoming._hour + TemporaryTime._hour) - DAY * days;
	}
	// Function return value
	return TemporaryTime;
}

// Overload operator + (object + hours)
Time Time :: operator + (const s_hour * my_hours)
{
	// New time
	Time TemporaryTime;
	// Fold hours
	TemporaryTime._hour = this->_hour + my_hours->hour;
	// Minutrs
	TemporaryTime._minute = this->_minute;
	// Seconds
	TemporaryTime._second = this->_second;
	// Function return value
	return TemporaryTime;
}

// Overload operator + (object + minutes)
Time Time :: operator + (const s_minute * my_minutes)
{
	// Variables
	int hours{};
	// New time
	Time TemporaryTime;
	// Seconds
	TemporaryTime._second = this->_second;
	// Fold minutes
	if ((this->_minute + my_minutes->minute) < HOUR)
	{
		// Minutes
		TemporaryTime._minute = this->_minute + my_minutes->minute;
	}
	else if ((this->_minute + my_minutes->minute) >= HOUR)
	{
		// How many hours
		hours = (int)((this->_minute + my_minutes->minute) / HOUR);
		// MInutes
		TemporaryTime._minute = this->_minute + my_minutes->minute - HOUR * hours;
	}
	// Fold hours
	TemporaryTime._hour = this->_hour + hours;
	// Function return value
	return TemporaryTime;
}

// Overload operator + (object + seconds)
Time Time :: operator + (const s_second * my_seconds)
{
	// Variables
	int hours{}, minutes{};
	// New time
	Time TemporaryTime;
	// Fold seconds
	if ((this->_second + my_seconds->second) < MINUTE)
	{
		// Seconds
		TemporaryTime._second = this->_second + my_seconds->second;
	}
	else if ((this->_second + my_seconds->second) >= MINUTE)
	{
		// How many minutes
		minutes = (int)((this->_second + my_seconds->second) / MINUTE);
		// Seconds
		TemporaryTime._second = (this->_second + my_seconds->second) - MINUTE * minutes;
		// Minutes
		TemporaryTime._minute = minutes;
		// Chech minutes
		if (TemporaryTime._minute >= HOUR)
		{
			// How many hours
			hours = (int)(TemporaryTime._minute / HOUR);
			// MInutes
			TemporaryTime._minute -= HOUR * hours;
			// Hours
			TemporaryTime._hour = hours;
		}
	}
	// Fold minutes
	TemporaryTime._minute += this->_minute;
	// Fold hours
	TemporaryTime._hour += this->_hour;
	// Function return value
	return TemporaryTime;
}

// Overload operator - (object - object)
Time Time :: operator - (Time & Time_incoming)
{
	// New time
	Time TemporaryTime;
	// Subtract hours
	TemporaryTime._hour = ((this->_hour - Time_incoming._hour) >= 0) ? this->_hour - Time_incoming._hour : -(this->_hour - Time_incoming._hour);
	// Subtract minutes
	TemporaryTime._minute = ((this->_minute - Time_incoming._minute) >= 0) ? this->_minute - Time_incoming._minute : -(this->_minute - Time_incoming._minute);
	// Subtract seconds
	TemporaryTime._second = ((this->_second - Time_incoming._second) >= 0) ? this->_second - Time_incoming._second : -(this->_second - Time_incoming._second);
	// Function return value
	return TemporaryTime;
}

// Overload operator - (object - hours)
Time Time :: operator - (const s_hour * my_hours)
{
	// New time
	Time TemporaryTime;
	// Hours
	TemporaryTime._hour = ((this->_hour - my_hours->hour) >= 0) ? this->_hour - my_hours->hour : -(this->_hour - my_hours->hour);
	// Minutrs
	TemporaryTime._minute = this->_minute;
	// Minutrs
	TemporaryTime._second = this->_second;
	// Function return value
	return TemporaryTime;
}

// Overload operator - (object - minutes)
Time Time :: operator - (const s_minute * my_minutes)
{
	// Variables
	int hours{};
	// New time
	Time TemporaryTime;
	// Seconds
	TemporaryTime._second = this->_second;
	// Subtract minutes
	if (my_minutes->minute < HOUR)
	{
		if (my_minutes->minute <= this->_minute)
		{
			// Minutes
			TemporaryTime._minute = this->_minute - my_minutes->minute;
			// Hours
			TemporaryTime._hour = this->_hour;
		}
		else
		{
			// Minutes
			TemporaryTime._minute = HOUR + (this->_minute - my_minutes->minute);
			// Hours
			TemporaryTime._hour = this->_hour - 1;
		}
	}
	else if (my_minutes->minute >= HOUR)
	{
		// How many hours
		hours = (int)(my_minutes->minute / HOUR);
		// Minutes
		if (my_minutes->minute - HOUR * hours <= this->_minute)
		{
			// Minutes
			TemporaryTime._minute = this->_minute - my_minutes->minute - HOUR * hours;
		}
		else
		{
			// Minutes
			TemporaryTime._minute = HOUR + (this->_minute - (my_minutes->minute - HOUR * hours));
			// Minutes
			++hours;
		}
		// Hours
		TemporaryTime._hour = ((this->_hour - hours) >= 0) ? this->_hour - hours : -(this->_hour - hours);
	}
	// Function return value
	return TemporaryTime;
}

// Overload operator - (object - seconds)
Time Time :: operator - (const s_second * my_seconds)
{
	// Variables
	int hours{}, minutes{};
	// New time
	Time TemporaryTime;
	// Subtract seconds
	if (my_seconds->second < MINUTE)
	{
		if (my_seconds->second <= this->_second)
		{
			// Seconds
			TemporaryTime._second = this->_second - my_seconds->second;
			// Minutes
			TemporaryTime._minute = this->_minute;
			// Hours
			TemporaryTime._hour = this->_hour;
		}
		else
		{
			// Seconds
			TemporaryTime._second = MINUTE + (this->_second - my_seconds->second);
			// Minutes
			TemporaryTime._minute = this->_minute - 1;
			// Hours
			TemporaryTime._hour = this->_hour;
		}
	}
	else if (my_seconds->second >= MINUTE)
	{
		// How many minutes
		minutes = (int)(my_seconds->second / MINUTE);
		// Seconds
		if (my_seconds->second - MINUTE * minutes <= this->_second)
		{
			// Seconds
			TemporaryTime._second = this->_second - (my_seconds->second - MINUTE * minutes);
		}
		else
		{
			// Seconds
			TemporaryTime._second = MINUTE + (this->_second - (my_seconds->second - MINUTE * minutes));
			// Minutes
			++minutes;
		}
		// Minutes and hours
		if (minutes < HOUR)
		{
			// Minutes
			TemporaryTime._minute = ((this->_minute - minutes) >= 0) ? this->_minute - minutes : -(this->_minute - minutes);
			// Hours
			TemporaryTime._hour = this->_hour;
		}
		else if (minutes >= HOUR)
		{
			// How many hours
			hours = (int)(minutes / HOUR);
			// Minutes
			TemporaryTime._minute = ((this->_minute - (minutes - HOUR * hours)) >= 0) ? this->_minute - (minutes - HOUR * hours) : -(this->_minute - (minutes - HOUR * hours));
			// Hours
			TemporaryTime._hour = ((this->_hour - hours) >= 0) ? this->_hour - hours : -(this->_hour - hours);
		}
	}
	// Function return value
	return TemporaryTime;
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
