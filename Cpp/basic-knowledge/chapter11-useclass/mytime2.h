//
// Created by zanejins on 2022/11/1.
//

#ifndef NEW_PROJECT_MYTIME2_H
#define NEW_PROJECT_MYTIME2_H

class Time{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h,int m=0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0,int m=0);
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(double n) const;
    void Show() const;
};

#endif //NEW_PROJECT_MYTIME2_H
