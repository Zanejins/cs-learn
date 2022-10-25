#include<iostream>
using namespace std;

unsigned int C_in_str(const char* str,char ch);
int main() {
    char mmm[15]="minium"; //string in an array

    char *wail = "ululate"; //wail points to string

    unsigned int ms = C_in_str(mmm,'m');
    unsigned int us = C_in_str(wail,'u');

    cout<< ms <<"m characters in " <<mmm<<endl;
    cout<< us <<"u characters in "<< wail<<endl;

    return 0;
}

unsigned int C_in_str(const char * str,char ch) {
    unsigned int count = 0;

    while(*str) {
        if(*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}
