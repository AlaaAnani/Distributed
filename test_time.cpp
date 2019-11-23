#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <unistd.h>
#include <queue>
using namespace std;

int main()
{
    queue <pair<int, pair<chrono::steady_clock::time_point, int>>> meh1;
    queue <chrono::steady_clock::time_point> meh;
    chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    //meh.push(start);
    usleep(4000);
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Printing took"
              << chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "micros.\n";
}