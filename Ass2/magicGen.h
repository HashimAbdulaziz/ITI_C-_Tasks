#include "meshostdio.h"
#include <thread>
#include <chrono>
#include <vector>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

using namespace std;


void GenerateMagicSquare(int n);
