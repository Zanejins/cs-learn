//
// Created by zanejins on 2022/11/1.
//

#include<iostream>
#include "mytime0.h"

//记录一下重载运算符的限制
/*
 * 1. 重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。
 * 2. 使用运算符时不能违反运算符原来的句法规则。例如操作符的操作数不能改变
 * 3. 不能创建新的运算符
 * 4: 大多数的运算符都可以通过成员或者非成员函数进行重载，但是下面的运算符只能通过成员函数进行重载，如赋值=、函数调用（）、下标运算符[],指针访问类成员的运算符->
 *
 */


int main() {
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;

    cout<<"planning time = ";
    planning.Show();
    cout<<endl;

    cout<<"coding time = ";
    coding.Show();
    cout<<endl;

    cout<<"fixing time = ";
    fixing.Show();
    cout<<endl;

    total = coding + fixing;
    cout<<"coding.sum(fixing_ = ";
    total.Show();
    cout<<endl;

    Time morefixing(3,28);
    cout<<"more fixing time = ";
    morefixing.Show();
    cout<<endl;

    total = morefixing.operator+(total);
    total.Show();
    cout<<endl;
    return 0;
}