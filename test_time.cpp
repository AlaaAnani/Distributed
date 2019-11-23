#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <unistd.h>
#include <queue>
using namespace std;
using namespace std::chrono;

int main()
{
    time_t t1 = clock();
   /* queue <pair<int, pair<chrono::steady_clock::time_point, int>>> meh1;
    queue <chrono::steady_clock::time_point> meh;
    chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    //meh.push(start);
    usleep(4000);
    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //int seconds = chrono::duration_cast<std::chrono::seconds>(end - start).count() ;
    while(true)
    {
            chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
             int seconds = chrono::duration_cast<std::chrono::seconds>(end-start).count() ;
             cout << seconds << endl;
             //usleep(1000000);
    }*/

    seconds ms = duration_cast< seconds >( system_clock::now().time_since_epoch());

        while(true)
        {
            seconds ms = duration_cast< seconds >( system_clock::now().time_since_epoch());
            cout << ms.count() << endl;
        }
}