// Include files
#include <iostream>

// Macroses
#define MAXIMUM_STRING_LENGTH 256

// Namespace std
using namespace std;

// Prototips
int PrintSelectionBlock(void);
inline void PrintEmptyLine();
int GetUserChoise(const char* choice_title);
inline void CleanStream();
void CutString(char*& string, const int& size);
int GetUserRangeInteger(const char request[], int minimum, int maximum);
int GetUserPositiveInteger(const char request[], int minimum = 0);
int GetUserInteger(const char request[]);

// Print task selection block
int PrintSelectionBlock(void)
{
	// Variable
	int user_choice{};
	// Clear console
	system("cls");
	// Print empty line
	PrintEmptyLine();
	// Print header of houmework.
	printf("Homework for April 25, 2020. Executor: Anichkin A.V.\n");
	// Print empty line
	PrintEmptyLine();
	printf("Class Time.\n");
	// Print empty line
	PrintEmptyLine();
	// Print operations
	printf("1. Create time (default).\n");
	printf("2. Create time (hours, minutes, seconds).\n");
	printf("3. Create time (hours).\n");
	printf("4. Create time (minutes).\n");
	printf("5. Create time (seconds).\n");
	printf("6. Add and subtract time (object and object).\n");
	printf("7. Add and subtract time (object and hours).\n");
	printf("8. Add and subtract time (object and minutes).\n");
	printf("9. Add and subtract time (object and seconds).\n");
	printf("10. Switch between 24 and 12 hour format.\n");
	printf("11. Time zone.\n");
	printf("12. Winner / summer time.\n");
	printf("13. Input time.\n");
	user_choice = GetUserChoise("Please select number of function (1 - 13 - numbers of functions; 0 - exit): ");
	// Print empty line
	PrintEmptyLine();
	// Function return value
	return user_choice;
}

// Get user choice
int GetUserChoise(const char* choice_title)
{
	// Variable
	bool user_string_check{};
	int user_choice{};
	char * user_string{};
	// Allocate memory
	user_string = new char[MAXIMUM_STRING_LENGTH] {'\0'};
	// Check pointer
	if (user_string)
	{
		// Get task number from user
		user_string_check = true;
		while (user_string_check)
		{
			// Print empty line
			PrintEmptyLine();
			// Enter user choice
			printf("%s", choice_title);
			// Get string from user
			cin >> user_string;
			// User enter 0
			if ((int)(*(user_string)) == 48)
			{
				// Exit
				user_choice = 0;
				user_string_check = false;
				// Clean stream
				CleanStream();
			}
			// User enter task number from 1 to 9
			else if (((int)(*(user_string)) >= 49 && (int)(*(user_string)) <= 57) && *(user_string + 1) == '\0')
			{
				// Cut string
				CutString(user_string, 1);
				// Convert string to number
				user_choice = atoi(user_string);
				// Check converting number
				if (user_choice > 0)
				{
					user_string_check = false;
				}
				// Clean stream
				CleanStream();
			}
			// User enter task number from 10 to 13
			else if (((int)(*(user_string)) >= 49 && (int)(*(user_string)) <= 57) && ((int)(*(user_string + 1)) >= 48 && (int)(*(user_string + 1)) <= 57))
			{
				// Cut string
				CutString(user_string, 2);
				// Convert string to number
				user_choice = atoi(user_string);
				// Check converting number
				if (user_choice > 0)
				{
					user_string_check = false;
				}
				// Clean stream
				CleanStream();
			}
			// Task not found
			else
			{
				// Task not found
				user_choice = -1;
				user_string_check = false;
				// Clean stream
				CleanStream();
			}
		}
		// Deallocate memory
		delete[] user_string;
		// Clean pointer
		user_string = nullptr;
	}
	// Function return value   	 
	return user_choice;
}

// Inline void function: "Clean stream"
inline void CleanStream()
{
	// Clear input stream
	cin.clear();
	while (cin.get() != '\n');
}

// Cut string
void CutString(char*& string, const int& size)
{
	// Variables
	char * new_string{};
	// Allocate memory
	new_string = new char[size + 1]{ '\0' };
	// Check pointer
	if (new_string)
	{
		// Fill cut string
		strcpy_s(new_string, size + 1, string);
		// Deallocate memory
		delete[] string;
		// Clean pointer
		string = nullptr;
		// Pointer to cut string
		string = new_string;
	}
}

// Print empty line
inline void PrintEmptyLine()
{
	// Print empty line
	printf("\n");
}

// Get range integer number from user
int GetUserRangeInteger(const char request[], int minimum, int maximum)
{
	// Variables
	int user_data{};
	bool condition{};
	// Get user data
	condition = true;
	while (condition)
	{
		// Print request
		printf("%s", request);
		// Get data from user
		cin >> user_data;
		// Clean stream
		CleanStream();
		// Check condition
		if (user_data >= minimum && user_data <= maximum)
		{
			// Convert condition
			condition = false;
		}
	}
	// Return int data from user
	return user_data;
}

// Get positive integer number from user
int GetUserPositiveInteger(const char request[], int minimum)
{
	// Variables
	int user_data{};
	bool condition{};
	// Get user data
	condition = true;
	while (condition)
	{
		// Print request
		printf("%s", request);
		// Get data from user
		cin >> user_data;
		// Clean stream
		CleanStream();
		// Check condition
		if (user_data >= minimum)
		{
			// Convert condition
			condition = false;
		}
	}
	// Return int data from user
	return user_data;
}

// Get integer number from user
int GetUserInteger(const char request[])
{
	// Variables
	int user_data{};
	// Print request
	printf("%s", request);
	// Get data from user
	cin >> user_data;
	// Clean stream
	CleanStream();
	// Return int data from user
	return user_data;
}