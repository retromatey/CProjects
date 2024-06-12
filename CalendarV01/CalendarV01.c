// Display a calendar view of the current month.
// Sample below:

//      June 2024
// S  M  T  W  T  F  S
// 1
// 2  3  4  5  6  7  8
// 9 10 11 12 13 14 15
// 16 17 18 19 20 21 22
// 23 24 25 26 27 28 29
// 30

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct tm get_local_time()
{
	time_t now;
	struct tm local_time;

	time(&now);
	errno_t err = localtime_s(&local_time, &now);

	if (err)
	{
		printf("Failed to convert current time to local time\n");
		exit(1);
	}

	return local_time;
}

struct tm get_first_of_month(struct tm local_time)
{
	local_time.tm_mday = 1;

	if (mktime(&local_time) == -1)
	{
		printf("Failed to adjust the time for first of month\n");
		exit(1);
	}

	return local_time;
}

void print_current_month_header(struct tm local_time)
{
	char* days_header = " S  M  T  W  T  F  S";

	char month[20];
	strftime(month, sizeof(month), "%B", &local_time);

	char year[10];
	strftime(year, sizeof(year), "%Y", &local_time);

	char month_year[40];
	sprintf_s(month_year, sizeof(month_year), "%s %s", month, year);

	// Calculate the length of the month_year string
	int len = strlen(month_year);

	// Calculate the number of spaces needed to center the month_year string above the days_header string
	int pad = (strlen(days_header) - len) / 2;

	// Print the month and year centered above the days of the week
	// The "%*s" format specifier is used to print the month_year string right-justified within a field of width 'pad + len'
	// The empty string at the end is used to print the remaining spaces needed to center the month_year string
	printf("%*s%s\n", pad + len, month_year, "");
	printf("%s\n", days_header);
}

void print_current_month(struct tm local_time)
{
	struct tm current_day = get_first_of_month(local_time);
	int current_month = local_time.tm_mon;
	int days_in_week = 7;

	while (current_day.tm_mon == current_month)
	{
		for (int i = 0; i < days_in_week; i++)
		{
			if (current_day.tm_wday == i)
			{
				printf("%2d ", current_day.tm_mday);
				current_day.tm_mday += 1;
				if (mktime(&current_day) == -1)
				{
					printf("Failed to update time\n");
					exit(1);
				}
			}
			else
			{
				printf("   ");
			}

			if (current_day.tm_mon != current_month)
			{
				break;
			}
		}

		printf("\n");
	}
}

int main(void)
{
	struct tm local_time = get_local_time();
	print_current_month_header(local_time);
	print_current_month(local_time);

	return 0;
}



// Some helpful links for this project's code:

// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l?view=msvc-170

// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170

// From https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/asctime-wasctime?view=msvc-170
// tm struct member	   Value
// tm_hour	           Hours since midnight(0 - 23)
// tm_isdst	           Positive if daylight saving time is in effect; 0 if daylight saving time isn't in effect; negative if status of 
//                     daylight saving time is unknown. The C run-time library assumes the United States' rules for implementing the 
//                     calculation of Daylight Saving Time(DST).
// tm_mday	           Day of month(1 - 31)
// tm_min	           Minutes after hour(0 - 59)
// tm_mon	           Month(0 - 11; January = 0)
// tm_sec	           Seconds after minute(0 - 59)
// tm_wday	           Day of week(0 - 6; Sunday = 0)
// tm_yday	           Day of year(0 - 365; January 1 = 0)
// tm_year	           Year(current year minus 1900)