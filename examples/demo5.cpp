// wapi.hpp with console

#include "..\wapi.hpp"

int main() {  // console main function
    std::cout << "The examples code with wapi.hpp | console";
    /*
    pause();
    cls();
    clearcolor(...);
    colorclear(...);
    Hide/Show Cursor();
    */

    pause();
    std::cout << "pause the console";
    pause();
    cls();
    std::cout << "clean the screen\nNormal Pause:";
    pause();
    std::cout << "No echo pause:";
    noEchoPause();
    std::cout << "No echo pause level up!\n(ง •_•)ง...";
    noEchoPause();
    std::cout << "Hide Console Cursor:";
    HideCursor();
    pause();
    std::cout << "Show Console Cursor:";
    ShowCursor();
    std::cout << "exit please press \'q\'...";
    noEchoPause();
    while(KEY_DOWN((int)'q')) {
        std::cout << "Your press \'a\' (0/1)?\n";
        std::cout << KEY_DOWN((int)'a');
        Sleep(20);
    }
    std::cout << "Goodbye!";

    return 0;
}