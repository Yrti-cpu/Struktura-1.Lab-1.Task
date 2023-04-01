#include "Time.h"

Time::Time()
{
    this->hours = 0;
    this->minutes = 0;
}
Time::Time(bool state, short hours, short minutes)
{
    if (state)
    {
        while (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60)
        {
            std::cin >> hours;
            std::cin.ignore(1024, ':');
            std::cin >> minutes;
        }
            this->hours = hours;
            this->minutes = minutes;

    }
    else
    {
        while (hours < 0 || hours >= 505 || minutes < 0 || minutes >= 60)
        {
            std::cin >> hours;
            std::cin.ignore(1024, ':');
            std::cin >> minutes;
        }
            this->hours = hours;
            this->minutes = minutes;
    }
    
    
}
Time::Time(const Time& t)
{
    this->hours = t.hours;
    this->minutes = t.minutes;
}
bool Time::operator<=(const Time other)
{
    if (this->GetHour() < other.hours){ return true; }
    else if (this->GetHour() == other.hours && this->GetMinutes() <= other.minutes){return true;}
    return false;
}
bool Time::operator ==(const Time other)
{
    if (this->GetHour() == other.hours && this->GetMinutes() == other.minutes){ return true; }
    return false;
}
std::ostream& operator<<(std::ostream& os, Time& time)
{
    if (time.hours < 10) { os << "0"; }
    os << time.hours << ":";
    if (time.minutes < 10) { os << "0"; }
    os << time.minutes;
    return os;
}
std::string to_string(const Time &time)
{
    std::string s;
    s = std::to_string(time.hours) + ':' + std::to_string(time.minutes);
    return s;
}
Time to_Time(std::string str)
{
    Time t1;
    t1.SetHour(atoi(str.substr(0, 2).c_str()));
    t1.SetMinutes(atoi(str.substr(3, 2).c_str()));
    return t1;
}