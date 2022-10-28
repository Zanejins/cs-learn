//template实例化和具体化
/*
template<typename T>
void Swap(T &a, T &b);      --------模板声明，只是告诉编译器生成函数的规则，自身并不会生成函数

int i,j;
swap(i,j);             --------隐式实例化，结合模板声明和传入的int信息，生成需要的函数定义

template void Swap<int>(int,int);  ---显式实例化，该声明的意思是“使用Swap模板生成int类型的函数定义”

template <> void Swap<int>(int &,int &);  --显式具体化，该声明的意思是“不要使用Swap模板来生成函数定义，而应使用专门为int类型显式定义的函数被定义”


template<class T>
void Swap(T &,T &);

template <> void Swap<job>(job &.job &);

int main() {
    template void Swap<char>(char &,char &);
    short a,b;
    swap(a,b);     //use implicit template instance for short
    
    
    job n,m;
    swap(n,m);    //use explicit specialization for job

    char g,h;     //use explicit instantiation for char
    swap(g,h);
}

*/


/* 那编译器选择使用那个函数版本呢？
第一步：创建候选函数列表。其中包含与被调用函数的名称相同的函数和函数模板
第二步：使用候选函数列表创建可行函数列表。这些都是参数数目正确的函数，为此有一个隐式转换序列，其中包含实参类型与相应的形参
       类型完全匹配的情况。
第三步：确定是否有最佳的可行函数，如果有，则使用它，否则该函数调用出错。

1. 完全匹配（注意常规函数优先于模板）
2，提升匹配
3，标准转换
4. 用户自定义的转换

何为完全匹配？
对于C++而言，完全匹配其实是可以允许一些“无关紧要的转换的”，比如const与非const、原型与引用，[]与指针等等。
这就可能照成同时有多个函数可以满足完全匹配的原则，这时就会出现二义性错误，但是有一个特例就是：
1. 指向非const数据的指针和引用优先与非const指针和引用参数匹配，但是只适用于指针和引用指向的数据
2. 完全匹配的普通函数优先级高于完全匹配的模板
3. 两个完全匹配的函数都是模板函数，则较具体的模板优先，这意味着显示具体化将优先于使用模板隐式生成的具体化：

*/

#include<iostream>

using namespace std;

template<typename T>
void Swap(T &a,T &b);

template<typename T>
void Swap(T *a,T *b ,int n);

void Show(int a[]);

const int Lim = 8;

int main() {
    int i=10;
    int j=20;

    cout<<"i,j = "<<i<<", "<<j<<".\n";
    cout<<"Using compiler-generated int swapper:\n";
    Swap(i,j);
    cout<<"Now i, j = "<<i<<", "<<j<<".\n";

    int d1[Lim]={0,7,0,4,1,7,7,6};
    int d2[Lim]={0,7,2,0,1,9,6,9};

    cout<<"Original arrays:\n";
    Show(d1);
    Show(d2);
    Swap(d1,d2,Lim);
    cout<<"Swapped arrays:\n";
    Show(d1);
    Show(d2);
    return 0;
}

template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<typename T>
void Swap(T *a,T *b,int n) {
    T temp;
    for(int i=0;i<n;i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[]) {
    using namespace std;

    cout<<a[0]<<a[1]<<"/";
    cout<<a[2]<<a[3]<<"/";
    for(int i=4;i<Lim;i++) {
        cout<<a[i];
    }
    cout<<endl;
}