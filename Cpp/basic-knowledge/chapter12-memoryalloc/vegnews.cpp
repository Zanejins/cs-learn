#include<iostream>
using std::cout;
#include "stringbad.h"

void callme1(StringBad &); //pass by reference
void callme2(StringBad); //pass by value

int main() {
    using std::endl;
    {
        cout<<"Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");

        cout<<"headline1: "<<headline1<<endl;
        cout<<"headline2: "<<headline2<<endl;
        cout<<"sports: "<<sports<<endl;

        callme1(headline1);
        cout<<"headline1: "<<headline1<<endl;

        //这里callme2按值传递，结果表明这时一个严重的问题
        //首先，将headline2作为函数参数来传递导致析构函数被调用，其次，虽然
        //按照值传递可以防止原始参数被修改，但实际上函数已使原字符串无法识别，导致
        //一些非标准字符。
        callme2(headline2); //将调用拷贝构造函数
        cout<<"headline2: "<<headline2<<endl;

        cout<<"Initialize one object to another:\n";
        StringBad sailor = sports;  //这将导致sailor释放了共同指向的字符串内存。
        cout<<"sailor: "<<sailor<<endl;
        cout<<"Assign one object to another:\n";
        StringBad kot;
        kot = headline1;
        cout<<"kot: "<<kot<<endl;
        cout<<"Exiting the block.\n";
    }
    //因为自动存储对象被删除的顺序与创建顺序相反，所以最先删除的3个
    //对象是knots、sailor和sport,删除knots和sailor时是正常的，但在删除sport时候，出现问题。
    //对于sport，程序只使用它来初始化sailor,但是这种操作修改了sport,最后三处两个对量headline2
    //和headline1已经无法识别。这写字符串在被三处之前，有些操作将它们搞乱了

    //实际上，计数异常是一条线索，因为每个对象被钩爪和析构一次，因为调用构造函数的次数应当与析构函数的调用次数相同。对象技术帝骖的次数比底层
    //的次数多2，这表明使用了不讲num_string递增的构造函数创建了两个对象。类定义声明并定义了两个构造函数，但结果表明程序使用了3个构造函数。
    //stringBad sailor = sports；
    //这使用那个构造函数呢》
    cout <<"End of main()\n";
    return 0;
}

void callme1(StringBad &rsb) {
    cout<<"String passed by reference:\n";
    cout<<"  \""<<rsb<<"\"\n";
}

void callme2(StringBad rsb) {
    cout<<"String passed by value:\n";
    cout<<"  \""<<rsb<<"\"\n";
}

