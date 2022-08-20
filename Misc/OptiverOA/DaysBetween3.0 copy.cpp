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

    // Get the number of years in the range [year1, year2]
    int yearsOverlapped = year2 - year1 + 1;
    int numLeapYearsTouched = getNumLeapYearsBetween(year1, year2);

    // Add the number of days attributable to the year difference
    daysBetween += (yearsOverlapped * 365) + numLeapYearsTouched;

    // Subtract days from beginning of year 1 to month 1 day 1
    int monthIndex = 1;
    while (monthIndex < month1)
    {
        daysBetween -= DaysInMonth(monthIndex, year1);
        monthIndex++;
    }
    daysBetween -= day1;
    
    // Subtract days from month 2 day 2 till end of year2
    monthIndex = 12;
    while (monthIndex > month2)
    {
        daysBetween -= DaysInMonth(monthIndex, year2);
        monthIndex--;
    }
    daysBetween -= DaysInMonth(month2, year2) - day2;
    return daysBetween;
}
