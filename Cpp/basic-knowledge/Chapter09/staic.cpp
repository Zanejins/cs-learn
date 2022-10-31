#include<iostream>
using namespace std;

const int ArSize = 10;

void strcount(const char * str);

int main() {
    using namespace std;
    char input[ArSize];
    char next;

    cout<<"Enter a line:\n";
    cin.get(input,ArSize);
    while(cin) {
        cin.get(next);
        while(next!='\n') {
            cin.get(next);
        }
        strcount(input);
        cout<<"Enter next line(empty line to quit):\n";
        cin.get(input,ArSize);
    }
    cout<<"Bye\n";
    return 0;
}

void strcount(const char * str) {
    using namespace std;
    static int total = 0; //每次函数调用时，自动变量count都被重制为0,静态变量total只在程序运行时被设置为0
    int count=0;
    cout<<"\""<<str<<"\" contains ";
    while(*str++) {
        count++;
    }
    total+=count;
    cout<<count<<" characters\n";
    cout<<total<<" characters total\n";
}

