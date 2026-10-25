#include <iostream>
using namespace std;

class Time
{
    int hours;
    int minutes;
    int seconds;
public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    explicit Time(int second)
    {
        hours = second / 3600;
        minutes = second / 60 % 60;
        seconds = second % 60;
    }
    int TurnIntoSeconds()const
    {
        int secondsNew = hours * 3600 + minutes * 60 + seconds;
        return secondsNew;
    }
    void TurnIntoTime(int time)
    {
        hours = time / 3600;
        minutes = time / 60 % 60;
        seconds = time % 60;
    }
    void Print()
    {
        if (hours < 10)
            cout << "0" << hours << ":";
        else
            cout << hours << ":";
        if (minutes < 10)
            cout << "0" << minutes << ":";
        else
            cout << minutes << ":";
        if (seconds < 10)
            cout << "0" << seconds << endl;
        else
            cout << seconds << endl;
    }
    void AddSecond()
    {
        int secondsNew = hours * 3600 + minutes * 60 + seconds + 1;
        TurnIntoTime(secondsNew);
    }
#pragma region Operators
    Time operator +(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        int SecondsOverall = SecondsThis + SecondsOther;
        Time NewTime(SecondsOverall);
        return NewTime;
    }
    Time operator -(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        int SecondsOverall = SecondsThis - SecondsOther;
        Time NewTime(SecondsOverall);
        return NewTime;
    }
    Time operator *(int number)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOverall = SecondsThis * number;
        Time NewTime(SecondsOverall);
        return NewTime;
    }
    Time operator /(int number)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOverall = SecondsThis / number;
        Time NewTime(SecondsOverall);
        return NewTime;
    }



    bool operator >(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        if (SecondsThis > SecondsOther)
            return true;
        else
            return false;
    }
    bool operator <(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        if (SecondsThis < SecondsOther)
            return true;
        else
            return false;
    }
    bool operator >=(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        if (SecondsThis >= SecondsOther)
            return true;
        else
            return false;
    }
    bool operator <=(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        if (SecondsThis <= SecondsOther)
            return true;
        else
            return false;
    }



    bool operator ==(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        if (SecondsThis == SecondsOther)
            return true;
        else
            return false;
    }
    bool operator !=(const Time& other)
    {
        int SecondsThis = TurnIntoSeconds();
        int SecondsOther = other.TurnIntoSeconds();
        if (SecondsThis != SecondsOther)
            return true;
        else
            return false;
    }
#pragma endregion

};

int main()
{
    Time time1(11, 59, 59);
    time1.Print();
    time1.AddSecond();
    time1.Print();
    Time time2(1, 30, 45);
    Time time3 = time1 + time2;
    time3.Print();
    time3 = time1 - time2;
    time3.Print();
    time3 = time1 * 2;
    time3.Print();
    time3 = time1 / 2;
    time3.Print();

    if (time1 > time2)
        cout << "left time is bigger" << endl;
    else
        cout << "right time is bigger" << endl;

    if (time2 < time3)
        cout << "right time is bigger" << endl;
    else
        cout << "left time is bigger" << endl;

    if (time1 >= time2)
        cout << "left time is bigger" << endl;
    else
        cout << "right time is bigger" << endl;

    if (time1 <= time2)
        cout << "right time is bigger" << endl;
    else
        cout << "left time is bigger" << endl;


    if (time1 == time2)
        cout << "Time are the same" << endl;
    else
        cout << "Time aren't the same" << endl;
    Time time4(12, 0, 0);
    if (time1 == time4)
        cout << "Time are the same" << endl;
    else
        cout << "Time aren't the same" << endl;
    if (time1 != time2)
        cout << "Time aren't the same" << endl;
    else
        cout << "Time are the same" << endl;
}