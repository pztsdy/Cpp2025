#include "define.h"
// sort

bool int_small_to_big(int x, int y)
{
    return x < y;
}

bool int_big_to_small(int x, int y)
{
    return x > y;
}

bool int_jFOS(int x, int y)
{
    if (x % 2 == 0 && y % 2 != 0)
        return x > y;
    if (x % 2 != 0 && y % 2 == 0)
        return y > x;
    return x > y;
}

bool int_oFjS(int x, int y)
{
    if (x % 2 == 0 && y % 2 != 0)
        return x < y;
    if (x % 2 != 0 && y % 2 == 0)
        return y < x;
    return x < y;
}

// insert your more cmp_function here (int)
// ...

bool ll_small_to_big(long long x, long long y)
{
    return x < y;
}

bool ll_big_to_small(long long x, long long y)
{
    return x > y;
}

// insert your more cmp_function here (long long)
// ...

float float_small_to_big(float x, float y)
{
    return x < y;
}

float float_big_to_small(float x, float y)
{
    return x > y;
}

// insert your more cmp_function here (float)
// ...

double double_small_to_big(double x, double y)
{
    return x < y;
}

double double_big_to_small(double x, double y)
{
    return x > y;
}

// insert your more cmp_function here (double)
// ...