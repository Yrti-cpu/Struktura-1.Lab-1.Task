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
            std::cout << "Error! Try again\n";
            std::cin >> hours;
            std::cin.ignore(1024, ':');
            std::cin >> minutes;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
            this->hours = hours;
            this->minutes = minutes;

    }
    else
    {
        while (hours < 0 || hours >= 505 || minutes < 0 || minutes >= 60 || (minutes == 0 && hours == 0))
        {
            std::cout << "Error! Try again\n";
            std::cin >> hours;
            std::cin.ignore(1024, ':');
            std::cin >> minutes;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
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
std::ostream& operator<<(std::ostream& os, Time time)
{
    os << std::setfill('0') << std::setw(2) << time.hours << ":" << std::setw(2) << time.minutes << std::setfill(' ');
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
    if (str.size() == 3)
    {
        t1.SetHour(atoi(str.substr(0, 1).c_str()));
        t1.SetMinutes(atoi(str.substr(2, 1).c_str()));
    }
    else if (str[1] == ':')
    {
        t1.SetHour(atoi(str.substr(0, 2).c_str()));
        t1.SetMinutes(atoi(str.substr(2, 2).c_str()));
    }
    else
    {
        t1.SetHour(atoi(str.substr(0, 2).c_str()));
        t1.SetMinutes(atoi(str.substr(3, 2).c_str()));
    }
    return t1;
}