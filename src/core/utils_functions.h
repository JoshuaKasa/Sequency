/*
 * File for all the types of utility functions
 * that are used in the library
 */

#ifndef UTILS_FUNCTIONS_H
#define UTILS_FUNCTIONS_H

#include <cmath>
#include <iostream>
#include "types.h"

bool is_power_of_two(int64 number);
bool is_even(int64 number);
bool is_odd(int64 number);
int64 next_power_of_two(int64 number);
int64 previous_power_of_two(int64 number);
int64 next_fibonacci_number(int64 number);

bool is_power_of_two(int64 number)
{
    return (number & (number - 1)) == 0;
}

bool is_even(int64 number)
{
    return (number & 1) == 0;
}

bool is_odd(int64 number)
{
    return (number & 1) == 1;
}

int64 next_power_of_two(int64 number)
{
    if (is_power_of_two(number))
    {
        return number;
    }

    int64 result = 1;
    while (result < number)
    {
        result <<= 1;
    }

    return result;
}

int64 previous_power_of_two(int64 number)
{
    if (is_power_of_two(number))
    {
        return number;
    }

    int64 result = 1;
    while (result < number)
    {
        result <<= 1;
    }

    return result >> 1;
}

int64 next_fibonacci_number(int64 number)
{
    if (number <= 0)
        return 0;
    if (number == 1)
        return 1;

    double phi = (1 + sqrt(5)) / 2;

    return static_cast<int64>(round(pow(phi, number) / sqrt(5)));
}

#endif // UTILS_FUNCTIONS_H