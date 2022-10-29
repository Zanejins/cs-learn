#include<iostream>

using namespace std;

void oil(int x);

/*
总结一下整个过程：
执行到main（）时，程序为texas和year分配空间，是的这些变量可见。
当程序调用oil时，这些变量仍然保留在内存中，但是不可见，
为新变量x和texas分配内存，从而是的它们可见。在程序执行到oil（）中的内部
代码块的时，新的texas将不可见，它被一个更新的定义代替，然而，变量x任然可见
，这时因为该代码块没有定义x变量，当程序流程离开该代码块时，将释放最新的texas使用
的内存，而第二个texas再次可见。当oil函数结束时，texas和x都将过期，而最初的texas
和year再次可见。
*/
int main() {
    using namespace std;

    int texas = 31;
    int year = 2011;
    cout<<"In main() , texas ="<<texas<<", &texas = "<<&texas<<endl;

    cout<<"In main() , year ="<<year<<"m &year = "<<&year<<endl;

    oil(texas);
 
    cout<<"In main() , texas ="<<texas<<", &texas = "<<&texas<<endl;

    cout<<"In main() , year ="<<year<<"m &year = "<<&year<<endl;

}

void oil(int x) {
    using namespace std;
    int texas = 5;

    cout<<"In oil() , texas ="<<texas<<", &texas = "<<&texas<<endl;

    cout<<"In oil() , x ="<<x<<" &x = "<<&x<<endl; //x作为形参是接收的实参的值，并创建了新的内存区域
    {
        int texas = 119;

        cout<<"In block, texas = "<<texas<<" ,&texas = "<<&texas<<endl; //会覆盖掉oil作用域下额texas
        cout<<"In block , x ="<<x<<"m &x = "<<&x<<endl;
    }
    cout<<"Post-block texas = "<<texas <<" ,&texas = "<<&texas<<endl;;
    
}