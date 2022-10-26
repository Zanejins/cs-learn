#include<iostream>

using namespace std;

//inline工具是C++新增的特性。C语言使用预处理器语句#define来提供宏--内联函数的原始实现
//如 #define SQUARE(X) X*X
//这并不是通过传递参数实现的，而是通过恩本替换来实现的
inline double square(double x) {return x*x;}

int main() {
    double a,b;
    double c=13.0;
    a=square(5.0);
    b=square(4.5+7.5);

    cout<<"a = "<<a<<", b = "<<b<<"\n";
    cout<<"c = "<<c;
    cout<<", C squared = "<<square(c++)<<"\n";
    cout<<"Now C = "<<c<<"\n";
    return 0; 
}