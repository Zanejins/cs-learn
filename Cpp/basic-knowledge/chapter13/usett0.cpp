#include<iostream>
#include "tabtenn0.h"

int main() {
    using std::cout;
    //注意到该程序实例化对象时将C风格字符串作为参数，但是构造函数的形参类型被声明为const string&。这将导致
    //类型不匹配，但是string类有一个将const char* 作为参数的构造函数，使用C-风格字符串初始化string对象时，
    //将自动调用这个构造函数。
    TableTennishPlayer player1("Chuck","Blizzard",true);
    TableTennishPlayer player2("Tara","Boomdea",false);

    player1.Name();
    if(player1.HasTable())
        cout<<": has a table\n";
    else
        cout<<": has not a table\n";

    player2.Name();
    if(player2.HasTable())
        cout<<": has a table";
    else
        cout<<": has not a table\n";

    return 0;
}