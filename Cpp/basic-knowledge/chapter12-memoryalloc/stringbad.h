#ifndef NEW_PROJECT_STRINGBAD_H
#define NEW_PROJECT_STRINGBAD_H

#include<iostream>
class StringBad{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const char* s);
    StringBad();
    ~StringBad();
    friend std::ostream & operator<<(std::ostream & os,const StringBad & st);

};
#endif //NEW_PROJECT_STRINGBAD_H
