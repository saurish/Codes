#include <iostream>
#include <iomanip>
#include <chrono>
#include <stack>
using namespace std;

typedef     std::chrono::time_point <std::chrono::system_clock>     TimePoint;
typedef     std::chrono::duration <double>                          Duration;

class TimeStamp{
    public:

        TimePoint       time_point;
        string          marker;

        TimeStamp(TimePoint t, string m) : time_point(t),
                                           marker(m) {}  
};

class RunTimeProfiler
{
    public:

        void            start           (string comment);
        void            end             (string comment);

    
    private:
        std::stack<TimeStamp>           time_stamp_stack;
};


void        RunTimeProfiler::start          (string comment)
{
    auto    start_time  =   std::chrono::system_clock::now();
    TimeStamp t_start(start_time, comment);

    time_stamp_stack.push(t_start);

    cout << std::setw(20) << "Start [" << time_stamp_stack.size() << "] " << std::setw(40) << comment << std::setw(20) << "0s" << endl;
}

void        RunTimeProfiler::end            (string comment)
{
    auto    end_time  =   std::chrono::system_clock::now();
    
    if(comment != time_stamp_stack.top().marker)
        assert(false);

    Duration    duration_sec    =   end_time - time_stamp_stack.top().time_point;

    cout << std::setw(20) << "End ["    << time_stamp_stack.size() << "] " << std::setw(40) << comment 
         << std::setw(20) << std::fixed << std::setprecision(2)    << duration_sec.count() << "s" << endl;

    time_stamp_stack.pop();
}
