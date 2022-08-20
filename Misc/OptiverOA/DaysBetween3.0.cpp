#include <bits/stdc++.h>
int DaysInMonth(int month, int year);
// Do not edit above this line. It is only shown so you can see the function signature.
/**
 * Pre: year2 >= year 1, otherwise return 0
 * Post: Returns the number of years divisible by `n` in the range 
 * [year1, year2]
 */
int getNumYearsDivisibleByNBetween(int year1, int year2, int n)
{
    if (year1 > year2)
    {
        return 0;
    }
    
    // Stores the distance of year2 from the last year
    // just before or equal to year1 that is divisible by n
    int yearDistance = 0;
    int divisibleYearCount = 0;
    
    if (year1 % n == 0)
    {
        divisibleYearCount = 1;
    }
    else
    {
        yearDistance += year1 % n;
    }
    
    yearDistance += year2 - year1;
    divisibleYearCount += yearDistance / n;
    
    return divisibleYearCount;
}

/**
 * Pre: year2 >= year1. Returns 0 otherwise.
 * Returns the number of leap years in the range [year1, year2]
 */
int getNumLeapYearsBetween(int year1, int year2)
{
    /* From Wikipedia on Leap years
    The following pseudocode determines whether a year is a leap year or a 
    common year in the Gregorian calendar (and in the proleptic Gregorian calendar 
    before 1582). The year variable being tested is the integer representing the 
    number of the year in the Gregorian calendar.

    if (year is not divisible by 4) then (it is a common year)
    else if (year is not divisible by 100) then (it is a leap year)
    else if (year is not divisible by 400) then (it is a common year)
    else (it is a leap year)
    
    In summary, all years divisible by 4 are leap years.
    */

    int numYearsDivisibleBy4 = getNumYearsDivisibleByNBetween(year1, year2, 4);
    int numYearsDivisibleBy100 = getNumYearsDivisibleByNBetween(year1, year2, 100);
    int numYearsDivisibleBy400 = getNumYearsDivisibleByNBetween(year1, year2, 400);
    
    return numYearsDivisibleBy4 - numYearsDivisibleBy100 + numYearsDivisibleBy400;
}

/*
 * Complete the function below.
 */
int DaysBetween(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int daysBetween = 0;
    
    // Edge case: if years match:
    if (year1 == year2)
    {
        if (month1 == month2)
        {
            return day2 - day1;
        }
        else
        {
            daysBetween += DaysInMonth(month1, year1) - day1;
            int monthIndex = month1 + 1;
            while (monthIndex != month2)
            {
                // This loop should break eventually, otherwise it means
                // invalid arguments.
                daysBetween += DaysInMonth(monthIndex, year1);
                monthIndex++;
            }
            daysBetween += day2;
            return daysBetween;
        }
    }
    else
    {
       // Count the number of years that are strictly > year1 and < year2
        int yearsStrictlyBetween = std::max(year2 - year1 - 1, 0);
        int numLeapYearsStrictlyBetween = getNumLeapYearsBetween(year1 + 1, year2 - 1);

        // Add the number of days attributable to the year difference
        daysBetween += (yearsStrictlyBetween * 365) + numLeapYearsStrictlyBetween;

        // Add days until end of year 1 from month 1 day 1
        daysBetween += DaysInMonth(month1, year1) - day1;
        int monthIndex = month1 + 1;
        while (monthIndex <= 12)
        {
            daysBetween += DaysInMonth(monthIndex, year1);
            monthIndex++;
        }
        
        // Add days from beginning of year 2 until month 2 day 2
        monthIndex = 1;
        while (monthIndex < month2)
        {
            daysBetween += DaysInMonth(monthIndex, year2);
            monthIndex++;
        }
        daysBetween += day2;
        return daysBetween;
    }
}
