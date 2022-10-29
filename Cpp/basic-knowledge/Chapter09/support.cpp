#include<iostream>
extern double warming; //use warming from another file

/*
既然可以选择使用全局变量或者局部变量，那么到底选择使用哪种呢？首先，全局变量很有吸引力，因为
所有的函数都可以访问全局变量，而不用传递参数。但是易于访问的代价很大--就是程序不可靠。计算经验
表明，程序越能避免对数据进行不必要的访问，就越能保持数据的完整性，通常情况下，应使用局部变量，
应在需要知晓时才传递数据，而不因该不加区分地使用全局变量来使数据可用。
然而，全局变量也有它的好处，例如，可以让多个函数可以使用同一个数据块，外部存储尤其适合表示常量数据，因为这样可以使用关键字const
来防止被修改。
*/

//可以使用外部变量（全局变量）在多文件程序的不同部分之间共享数据
//可以使用连接性为内部的静态变量在同一个文件中的多个函数之间共享数据。

void update(double dt);
void local();

using std::cout;

void update(double dt) {
    extern double warming; //modifies global variable
    warming += dt;
    cout<<"update global warming to "<<warming <<" degrees.\n";
}

void local() {
    double warming = 0.8;  //new variable hides external one
    cout<<"local warming is "<<warming <<" degrees.\n";
    cout<<"But global warming is "<<::warming <<" degrees.\n";
}