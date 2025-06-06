// Copyright by pztsdy in 2025


// C++ 2025 include & define


#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <psapi.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "oleaut32.lib")

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <windows.h>


#ifdef __cpp2025
  #if __cpp2025 < 0x090
  #define __cpp2025 0x090
  #endif
#endif

#ifndef __cpp2025
  #define __cpp2025 0x090
#endif


// Winapi abbreviation
#define SetConsoleTextColor SetConsoleTextAttribute

// test
  // #define cc ClearColor(GetStdHandle(STD_OUTPUT_HANDLE), false, false)
  // #define stwl SetConsoleTextColor(GetStdHandle(STD_OUTPUT_HANDLE), TEXT_WHITE | TEXT_LIGHT)
  // #define strl SetConsoleTextColor(GetStdHandle(STD_OUTPUT_HANDLE), TEXT_RED | TEXT_LIGHT)

// #define ll long long