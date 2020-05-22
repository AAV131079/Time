#ifndef _TIME_H_
#define _TIME_H_

// Structures
// Hour
struct s_hour
{
	int hour;
};
// Minute
struct s_minute
{
	int minute;
};
// Second
struct s_second
{
	int second;
};

// Class Time
class Time
{
public:
	Time() : _hour{ 0 }, _minute{ 0 }, _second{ 0 }, _type_clock{ 1 }, _am_pm{ 0 }, _type_time{ 1 } {};		// Constructor without parameters
	Time(int hour, int minute, int second = 0);																// Constructor with parameters
	Time(const s_hour * my_hours);																			// Constructor with parameters
	Time(const s_minute * my_minutes);																		// Constructor with parameters
	Time(const s_second * my_seconds);																		// Constructor with parameters
	Time(float hour, float minute, float second) = delete;													// Ñonstructor call barring
	Time(double hour, double minute, double second) = delete;												// Ñonstructor call barring
	Time(const Time & Time_incoming);																		// Copt constructor
	Time(const Time && Time_incoming);																		// Transfer constructor
	~Time();																								// Destructor
	Time & operator = (const Time & Time_incoming);															// Copy assignment operator overload
	Time & operator = (const Time && Time_incoming);														// Transfer assignment operator overload
	Time operator + (Time & Time_incoming);																	// Overload operator + (object + object)
	Time operator + (const s_hour * my_hours);																// Overload operator + (object + hours)
	Time operator + (const s_minute * my_minutes);															// Overload operator + (object + minutes)
	Time operator + (const s_second * my_seconds);															// Overload operator + (object + seconds)
	Time operator - (Time & Time_incoming);																	// Overload operator - (object - object)
	Time operator - (const s_hour * my_hours);																// Overload operator - (object - hours)
	Time operator - (const s_minute * my_minutes);															// Overload operator - (object - minutes)
	Time operator - (const s_second * my_seconds);															// Overload operator - (object - seconds)
	void SetHour(int hour);																					// Set hours
	void SetMinute(int minute);																				// Set minutes
	void SetSecond(int second);																				// Set seconds
	void SetTypeClock(int typeclock);																		// Set clock type
	void SetAM_PM(int am_pm);																				// Set midday and midnight designations
	void SetTypeTime(int type_time);																		// Set type time
	int GetHour();																							// Get hours
	int GetMinute();																						// Get minutes
	int GetSecond();																						// Get seconds
	int GetTypeClock();																						// Get clock type
	int GetAMPM();																							// Get midday and midnight designations
	int GetTypeTime();																						// Get type time
	void ChangeTimeFormat();																				// Change time format
	void ChangeTimeZone(int hour, int minute = 0);															// Change time zone
	void ClockChange();																						// Clock change (switch to winter / summer time)
	void InputTime(int hour, int minute, int second = 0);													// Input time
	void ShowTime();																						// Show time
private:
	int _hour;																								// Hours
	int _minute;																							// Minutes
	int _second;																							// Seconds
	int _type_clock;																						// Clock type (1 - 24 hours format, 2 - 12 hours format)
	int _am_pm;																								// Midday and midnight designations (1 - a.m., 2 - p.m.)
	int _type_time;																							// Type of time (1 - summer time, 2 - winter time)
};

#endif
