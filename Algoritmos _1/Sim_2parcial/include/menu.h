#pragma once

#include <iostream>
#include <limits>

using namespace std;

class Menu 
{
    public:
        static int showMainMenu();
        static string readString(const string& prompt);
        static float readFloat(const string& prompt);
};
