//
// Created by zanejins on 2022/11/11.
//

#ifndef NEW_PROJECT_STUDENTI_H
#define NEW_PROJECT_STUDENTI_H

#include<iostream>
#include<valarray>
#include<string>

class Student : private std::string,private std::valarray<double> {
private:
    typedef std::valarray<double> ArrayDb;
    std::ostream & arr_out(std::ostream & os) const;

public:
    Student():std::string("Null Student"),ArrayDb() {}
    explicit Student(const std::string& s) : std::string(s),ArrayDb() {}
    explicit Student(int n) : std::string("Nully"),ArrayDb(n) {}

    Student(const std::string s,const ArrayDb & a) : std::string(s) , ArrayDb(a) {}

    Student(const char * str,const double * pd,int n) : std::string(str),ArrayDb(pd,n) {}

    ~Student() { }
    double Average() const;
    const std::string& Name() const;
    double& operator[](int i);
    double operator[](int i) const;


    //friend func
    friend std::istream& operator>>(std::istream& is,Student &stu);
    friend std::istream& getline(std::istream& is,Student &stu);
    friend std::ostream& operator<<(std::ostream& os,Student &stu);
};

#endif //NEW_PROJECT_STUDENTI_H
