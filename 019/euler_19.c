#include <stdbool.h>
#include <stdio.h>

bool is_leap(unsigned int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main(int argc, char *argv[])
{
    unsigned int lookup[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    unsigned int year = 1900,
                 month = 0,
                 days = 0,
                 first = 0,
                 sundays = 0;

    while (year < 2001) {
        days = lookup[month];
        if (month == 1 && is_leap(year)) {
            days++;
        }
        first = (first + days) % 7;
        if (year > 1900 && first == 6) {
            sundays++;
        }
        month++;
        if (month > 11) {
            year++;
            month = 0;
        }
    }
    printf("#sundays: %d\n", sundays);
}
