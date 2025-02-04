#include <iostream>
#include <vector>
#include "..\Algorithm.hpp" // 假设这些函数在Algorithm.hpp中定义

using namespace std;

int main()
{
    int n, a[13] = {0, 4, 1, 12, 9, 6, 5, 3, 2, 7, 8, 10, 11}; // 修正数组大小为13
    cout << "Enter a number: ";
    cin >> n;
    cout << "factorial(" << n << ") = " << factorial(n) << endl;
    cout << "fibonacci(" << n << ") = " << fibonacci(n) << endl;
    cout << "Pow(2, " << n << ") = " << Pow(2, n) << endl;
    cout << "gcd(12, " << n << ") = " << gcd(12, n) << endl;
    cout << "lcm(12, " << n << ") = " << lcm(12, n) << endl;
    cout << "isPrime(" << n << ") = " << isPrime(n) << endl;
    vector<int> primes = sieve_prime(n);
    cout << "Primes less than or equal to " << n << ": ";
    for (int i = 0; i < primes.size(); ++i)
    {
        cout << primes[i] << " ";
    }
    cout << endl;
    cout << "Binary search for " << n << " in the array: ";
    for (int i = 0; i < 13; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    vector<int> vec(a, a + 13);
    cout << " = " << binarySearch(vec, n) << endl; // 修正binarySearch函数调用，移除多余的参数
    cout << "Quick select for " << n << " in the array: ";
    for (int i = 0; i < 13; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    vector<int> vec(a, a + 13);
    cout << " = " << quickSelect(vec, 0, 12, n) << endl;

    return 0;
}