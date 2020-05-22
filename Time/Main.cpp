// Include files
#include "Time.h"
#include <iostream>

#define EXIT 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define ELEVEN 11
#define TWELVE 12
#define THIRTEEN 13

// Structures
s_hour* user_hours{};
s_minute* user_minutes{};
s_second* user_seconds{};

// Prototips
int PrintSelectionBlock(void);
inline void PrintEmptyLine();
int GetUserChoise(const char* choice_title);
inline void CleanStream();
void CutString(char*& string, const int& size);
int GetUserRangeInteger(const char request[], int minimum, int maximum);
int GetUserPositiveInteger(const char request[], int minimum = 0);
int GetUserInteger(const char request[]);
void Create_time_default();
void Create_time_hours_minutes_seconds();
void Create_time_hours_test();
void Create_time_minutes_test();
void Create_time_seconds_test();
void Add_and_subtract_time_object_and_object_test();
void Add_and_subtract_time_object_and_hours_test();
void Add_and_subtract_time_object_and_minutes_test();
void Add_and_subtract_time_object_and_seconds_test();
void Switch_between_24_and_12_hour_format_test();
void Time_zone_test();
void Winner_summer_time_test();
void Input_time_test();

// Main functuion
int main(void)
{
	// Variables
	int user_choice{};

	// Title of console
	system("title Homework for April 25, 2020. Executor: Anichkin A.V.");
	// Cycle waiting user choice
	while (true)
	{
		// Block selection of task
		user_choice = PrintSelectionBlock();
		// Exit console aplication
		if (user_choice == EXIT)
		{
			// Print mesage about exit
			printf("Work of console aplication is finished. Goodbye!\n\n");
			break;
		}
		switch (user_choice)
		{
			// 1. Create time (default)
		case(ONE):
		{
			// Test function
			Create_time_default();
			// Pause
			system("pause");
			break;
		}
		// 2. Create time (hours, minutes, seconds)
		case(TWO):
		{
			// Test function
			Create_time_hours_minutes_seconds();
			// Pause
			system("pause");
			break;
		}
		// 3. Create time (hours)
		case(THREE):
		{
			// Test function
			Create_time_hours_test();
			// Pause
			system("pause");
			break;
		}
		// 4. Create time (minutes)
		case(FOUR):
		{
			// Test function
			Create_time_minutes_test();
			// Pause
			system("pause");
			break;
		}
		// 5. Create time (seconds)
		case(FIVE):
		{
			// Test function
			Create_time_seconds_test();
			// Pause
			system("pause");
			break;
		}
		// 6. Add and subtract time (object and object)
		case(SIX):
		{
			// Test function
			Add_and_subtract_time_object_and_object_test();
			// Pause
			system("pause");
			break;
		}
		// 7. Add and subtract time (object and hours)
		case(SEVEN):
		{
			// Test function
			Add_and_subtract_time_object_and_hours_test();
			// Pause
			system("pause");
			break;
		}
		// 8. Add and subtract time (object and minutes)
		case(EIGHT):
		{
			// Test function
			Add_and_subtract_time_object_and_minutes_test();
			// Pause
			system("pause");
			break;
		}
		// 9. Add and subtract time (object and seconds)
		case(NINE):
		{
			// Test function
			Add_and_subtract_time_object_and_seconds_test();
			// Pause
			system("pause");
			break;
		}
		// 10. Switch between 24 and 12 hour format
		case(TEN):
		{
			// Test function
			Switch_between_24_and_12_hour_format_test();
			// Pause
			system("pause");
			break;
		}
		// 11. Time zone
		case(ELEVEN):
		{
			// Test function
			Time_zone_test();
			// Pause
			system("pause");
			break;
		}
		// 12. Winner / summer time
		case(TWELVE):
		{
			// Test function
			Winner_summer_time_test();
			// Pause
			system("pause");
			break;
		}
		// 13. Input time
		case(THIRTEEN):
		{
			// Test function
			Input_time_test();
			// Pause
			system("pause");
			break;
		}
		// Default
		default:
		{
			// Task not found
			printf("Task not found.\n");
			// Print empty line
			PrintEmptyLine();
			// Pause
			system("pause");
			break;
		}
		}
	}
	return EXIT_SUCCESS;
}

// 1. Create time (default)
void Create_time_default()
{
	// Print header
	printf("1. Create time (default).\n");
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time;
	// Print header
	printf("Time: ");
	// Print time
	time.ShowTime();
	// Delete time
	time.~Time();
	// Print empty line
	PrintEmptyLine();
}

// 2. Create time (hours, minutes, seconds)
void Create_time_hours_minutes_seconds()
{
	// Allocate memory
	user_hours = new s_hour[1]{};
	user_minutes = new s_minute[1]{};
	user_seconds = new s_second[1]{};
	// Print header
	printf("2. Create time (hours, minutes, seconds).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserRangeInteger("Please input hours (0...23): ", 0, 23);
	// Get hours
	user_minutes->minute = GetUserRangeInteger("Please input minutes (0...59): ", 0, 59);
	// Get hours
	user_seconds->second = GetUserRangeInteger("Please input seconds (0...59): ", 0, 59);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_hours->hour, user_minutes->minute, user_seconds->second);
	// Print header
	printf("Time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	delete[] user_minutes; user_minutes = nullptr;
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time.~Time();
}

// 3. Create time (hours).
void Create_time_hours_test()
{
	// Allocate memory
	user_hours = new s_hour[1]{};
	// Print header
	printf("3. Create time (hours).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserPositiveInteger("Please input time in hours (can not be less than 0): ", 0);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_hours);
	// Print header
	printf("Time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	// Delete time
	time.~Time();
}

// 4. Create time (minutes)
void Create_time_minutes_test()
{
	// Allocate memory
	user_minutes = new s_minute[1]{};
	// Print header
	printf("4. Create time (minutes).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_minutes->minute = GetUserPositiveInteger("Please input time in minutes (can not be less than 0): ", 0);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_minutes);
	// Print header
	printf("Time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_minutes; user_minutes = nullptr;
	// Delete time
	time.~Time();
}

// 5. Create time (seconds)
void Create_time_seconds_test()
{
	// Allocate memory
	user_seconds = new s_second[1]{};
	// Print header
	printf("5. Create time (seconds).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_seconds->second = GetUserPositiveInteger("Please input time in seconds (can not be less than 0): ", 0);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_seconds);
	// Print header
	printf("Time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time.~Time();
}

// 6. Add and subtract time (object and object)
void Add_and_subtract_time_object_and_object_test()
{
	// Create time
	Time time_1, time_2, time_3, time_4;
	// Print header
	printf("6. Add and subtract time (object and object).\n");
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Please input first time (h:m:s).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	time_1.SetHour(GetUserRangeInteger("Please input hours (0...23): ", 0, 23));
	// Get minutes
	time_1.SetMinute(GetUserRangeInteger("Please input minutes (0...59): ", 0, 59));
	// Get seconds
	time_1.SetSecond(GetUserRangeInteger("Please input seconds (0...59): ", 0, 59));
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Please input second time (h:m:s).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	time_2.SetHour(GetUserRangeInteger("Please input hours (0...23): ", 0, 23));
	// Get minutes
	time_2.SetMinute(GetUserRangeInteger("Please input minutes (0...59): ", 0, 59));
	// Get seconds
	time_2.SetSecond(GetUserRangeInteger("Please input seconds (0...59): ", 0, 59));
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("First time: ");
	// Print time
	time_1.ShowTime();
	// Print header
	printf("Second time: ");
	// Print time
	time_2.ShowTime();
	// Add time
	time_3 = time_1 + time_2;
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Time addition result: ");
	// Print time
	time_3.ShowTime();
	// Subtract time
	time_4 = time_1 - time_2;
	// Print header
	printf("Time subtract result: ");
	// Print time
	time_4.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Delete time
	time_1.~Time();
	time_2.~Time();
	time_3.~Time();
	time_4.~Time();
}

// 7. Add and subtract time (object and hours)
void Add_and_subtract_time_object_and_hours_test()
{
	// Create time
	Time time_1, time_2, time_3, time_4;
	// Allocate memory
	user_hours = new s_hour[1]{};
	// Print header
	printf("7. Add and subtract time (object and hours).\n");
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Please input first time (h:m:s).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	time_1.SetHour(GetUserRangeInteger("Please input hours (0...23): ", 0, 23));
	// Get minutes
	time_1.SetMinute(GetUserRangeInteger("Please input minutes (0...59): ", 0, 59));
	// Get seconds
	time_1.SetSecond(GetUserRangeInteger("Please input seconds (0...59): ", 0, 59));
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserPositiveInteger("Please input second time in hours (can not be less than 0): ", 0);
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("First time: ");
	// Print time
	time_1.ShowTime();
	// Print header
	printf("Second time: %i hours.\n", user_hours->hour);
	// Add time
	time_2 = time_1 + user_hours;
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Time addition result: ");
	// Print time
	time_2.ShowTime();
	// Subtract time
	time_3 = time_1 - user_hours;
	// Print header
	printf("Time subtract result: ");
	// Print time
	time_3.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	// Delete time
	time_1.~Time();
	time_2.~Time();
	time_3.~Time();
}

// 8. Add and subtract time (object and minutes)
void Add_and_subtract_time_object_and_minutes_test()
{
	// Create time
	Time time_1, time_2, time_3, time_4;
	// Allocate memory
	user_minutes = new s_minute[1]{};
	// Print header
	printf("8. Add and subtract time (object and minutes).\n");
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Please input first time (h:m:s).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	time_1.SetHour(GetUserRangeInteger("Please input hours (0...23): ", 0, 23));
	// Get minutes
	time_1.SetMinute(GetUserRangeInteger("Please input minutes (0...59): ", 0, 59));
	// Get seconds
	time_1.SetSecond(GetUserRangeInteger("Please input seconds (0...59): ", 0, 59));
	// Print empty line
	PrintEmptyLine();
	// Get minutes
	user_minutes->minute = GetUserPositiveInteger("Please input second time in minutes (can not be less than 0): ", 0);
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("First time: ");
	// Print time
	time_1.ShowTime();
	// Print header
	printf("Second time: %i minutes.\n", user_minutes->minute);
	// Add time
	time_2 = time_1 + user_minutes;
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Time addition result: ");
	// Print time
	time_2.ShowTime();
	// Subtract time
	time_3 = time_1 - user_minutes;
	// Print header
	printf("Time subtract result: ");
	// Print time
	time_3.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_minutes; user_minutes = nullptr;
	// Delete time
	time_1.~Time();
	time_2.~Time();
	time_3.~Time();
}

// 9. Add and subtract time (object and seconds)
void Add_and_subtract_time_object_and_seconds_test()
{
	// Create time
	Time time_1, time_2, time_3, time_4;
	// Allocate memory
	user_seconds = new s_second[1]{};
	// Print header
	printf("9. Add and subtract time (object and seconds).\n");
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Please input first time (h:m:s).\n");
	// Print empty line
	PrintEmptyLine();
	// Get hours
	time_1.SetHour(GetUserRangeInteger("Please input hours (0...23): ", 0, 23));
	// Get minutes
	time_1.SetMinute(GetUserRangeInteger("Please input minutes (0...59): ", 0, 59));
	// Get seconds
	time_1.SetSecond(GetUserRangeInteger("Please input seconds (0...59): ", 0, 59));
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_seconds->second = GetUserPositiveInteger("Please input second time in seconds (can not be less than 0): ", 0);
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("First time: ");
	// Print time
	time_1.ShowTime();
	// Print header
	printf("Second time: %i seconds.\n", user_seconds->second);
	// Add time
	time_2 = time_1 + user_seconds;
	// Print empty line
	PrintEmptyLine();
	// Print header
	printf("Time addition result: ");
	// Print time
	time_2.ShowTime();
	// Subtract time
	time_3 = time_1 - user_seconds;
	// Print header
	printf("Time subtract result: ");
	// Print time
	time_3.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time_1.~Time();
	time_2.~Time();
	time_3.~Time();
}

// 10. Switch between 24 and 12 hour format
void Switch_between_24_and_12_hour_format_test()
{
	// Print header
	printf("10. Switch between 24 and 12 hour format.\n");
	// Allocate memory
	user_hours = new s_hour[1]{};
	user_minutes = new s_minute[1]{};
	user_seconds = new s_second[1]{};
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserRangeInteger("Please input hours (0...23): ", 0, 23);
	// Get hours
	user_minutes->minute = GetUserRangeInteger("Please input minutes (0...59): ", 0, 59);
	// Get hours
	user_seconds->second = GetUserRangeInteger("Please input seconds (0...59): ", 0, 59);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_hours->hour, user_minutes->minute, user_seconds->second);
	// Print header
	printf("Time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Change time format
	time.ChangeTimeFormat();
	// Print header
	printf("Time (12h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	delete[] user_minutes; user_minutes = nullptr;
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time.~Time();
}

// 11. Time zone
void Time_zone_test()
{
	// Variables
	int hours_offset{}, minutes_offset{};
	// Print header
	printf("11. Time zone.\n");
	// Allocate memory
	user_hours = new s_hour[1]{};
	user_minutes = new s_minute[1]{};
	user_seconds = new s_second[1]{};
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserRangeInteger("Please input hours (0...23): ", 0, 23);
	// Get hours
	user_minutes->minute = GetUserRangeInteger("Please input minutes (0...59): ", 0, 59);
	// Get hours
	user_seconds->second = GetUserRangeInteger("Please input seconds (0...59): ", 0, 59);
	// Print empty line
	PrintEmptyLine();
	// Get hours offset
	hours_offset = GetUserInteger("Please enter the offset of the new time zone (hours): ");
	// Get minutes offset
	minutes_offset = GetUserInteger("Please enter the offset of the new time zone (minutes): ");
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_hours->hour, user_minutes->minute, user_seconds->second);
	// Print header
	printf("Time in old time zone (24h format): ");
	// Print time
	time.ShowTime();
	// New time zone
	time.ChangeTimeZone(hours_offset, minutes_offset);
	// Print header
	printf("Time in new time zone (%i:%i) (24h format): ", hours_offset, minutes_offset);
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	delete[] user_minutes; user_minutes = nullptr;
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time.~Time();
}

// 12. Winner / summer time
void Winner_summer_time_test()
{
	// Print header
	printf("12. Winner / summer time.\n");
	// Allocate memory
	user_hours = new s_hour[1]{};
	user_minutes = new s_minute[1]{};
	user_seconds = new s_second[1]{};
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserRangeInteger("Please input hours (0...23): ", 0, 23);
	// Get hours
	user_minutes->minute = GetUserRangeInteger("Please input minutes (0...59): ", 0, 59);
	// Get hours
	user_seconds->second = GetUserRangeInteger("Please input seconds (0...59): ", 0, 59);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_hours->hour, user_minutes->minute, user_seconds->second);
	// Print header
	printf("Summer time (24h format): ");
	// Print time
	time.ShowTime();
	// Winter time
	time.ClockChange();
	// Print header
	printf("Winter time (24h format): ");
	// Print time
	time.ShowTime();
	// Summer time
	time.ClockChange();
	// Print header
	printf("Summer time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	delete[] user_minutes; user_minutes = nullptr;
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time.~Time();
}

// 13. Input time
void Input_time_test()
{
	// Print header
	printf("13. Input time.\n");
	// Print empty line
	PrintEmptyLine();
	// Allocate memory
	user_hours = new s_hour[1]{};
	user_minutes = new s_minute[1]{};
	user_seconds = new s_second[1]{};
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserRangeInteger("Please input hours (0...23): ", 0, 23);
	// Get hours
	user_minutes->minute = GetUserRangeInteger("Please input minutes (0...59): ", 0, 59);
	// Get hours
	user_seconds->second = GetUserRangeInteger("Please input seconds (0...59): ", 0, 59);
	// Print empty line
	PrintEmptyLine();
	// Create time
	Time time(user_hours->hour, user_minutes->minute, user_seconds->second);
	// Print header
	printf("Time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Get hours
	user_hours->hour = GetUserRangeInteger("Please input new hours (0...23): ", 0, 23);
	// Get hours
	user_minutes->minute = GetUserRangeInteger("Please input new minutes (0...59): ", 0, 59);
	// Get hours
	user_seconds->second = GetUserRangeInteger("Please input new seconds (0...59): ", 0, 59);
	// Print empty line
	PrintEmptyLine();
	// Input time
	time.InputTime(user_hours->hour, user_minutes->minute, user_seconds->second);
	// Print header
	printf("New time (24h format): ");
	// Print time
	time.ShowTime();
	// Print empty line
	PrintEmptyLine();
	// Deallocate memory and clear pointer
	delete[] user_hours; user_hours = nullptr;
	delete[] user_minutes; user_minutes = nullptr;
	delete[] user_seconds; user_seconds = nullptr;
	// Delete time
	time.~Time();
}