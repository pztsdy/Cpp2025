#include "define.h"
#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#endif 


// Algorithm
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int Pow(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        int y = Pow(x, n / 2);
        return y * y;
    }
    else
    {
        return x * Pow(x, n - 1);
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

#include <vector>
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime[n];
}

std::vector<int> sieve_prime(int n)
{
    std::vector<bool> is_prime(n + 1, true);
    std::vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int binarySearch(const std::vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int quickSelect(std::vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return quickSelect(arr, left, pivotIndex - 1, k);
    else
        return quickSelect(arr, pivotIndex + 1, right, k);
}

int selectKthSmallest(std::vector<int> &arr, int k)
{ // support for k = 0, 1, 2, ...
    return quickSelect(arr, 0, arr.size() - 1, k);
}

int partition(std::vector<int> &arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; ++i)
    {
        if (arr[i] < pivotValue)
        {
            std::swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }
    std::swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

