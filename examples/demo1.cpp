#include <iostream>
// #include "wapi.hpp"
#include "..\wapi.hpp"

int main() {
    POINT mouse;
    int x = 100, y = 100;
    MoveMouse(mouse, x, y);
    std::cout << "press any key to continue..." << std::endl;
    pause();
    std::cout << "Set window title to \"Hello, World!\"" << std::endl;
    SetWindowTitle(GetConsoleWindow(), "Hello, World!");
    std::cout << "change console color to red" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TEXT_RED);
    std::cout << "TEXT TEXT TEXT" << std::endl;
    std::cout << "clear console color" << std::endl;
    colorclear(GetStdHandle(STD_OUTPUT_HANDLE));
    pause();
    std::cout << "clear the screen" << std::endl; // Fixed typo: "scree" to "screen"
    cls();
    std::cout << "Change the system volume to 50%" << std::endl;
    SetSystemVolume((DWORD)50);
    pause();
    int width, height;
    GetScreenResolution(width, height);
    std::cout << "The screen resolution is " << width << "x" << height << std::endl;
    pause();

    SYSTEMTIME systemTime;
    GetSystemTime(&systemTime);
    std::cout << "The system time is " 
              << systemTime.wHour << ":" 
              << systemTime.wMinute << ":" 
              << systemTime.wSecond << std::endl;
    pause();

    std::cout << "Simulate key press \"a\"" << std::endl;
    char charge;
    std::cin.get(charge);
    SimulateKeyPress('a'); // Removed unnecessary input
    std::cout << "Input Key: " << charge << std::endl;
    std::cout << "thanks for using wapi.hpp!" << std::endl;

    std::cout << "Demo program using wapi.hpp" << std::endl;
    pause();

    return 0;
}