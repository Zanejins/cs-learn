#include<iostream>
#include<string>
#include<new>

using namespace std;

const int BUF = 512;

class JustTesting{
private:
    string words;
    int number;
public:
    JustTesting(const string& s="Just Testing",int n=0){
        words =s;
        number=n;
    }
    void Show() const {
        cout<<words<<", "<<number<<endl;
    }
};

int main() {
    char *buffer = new char[BUF];
    JustTesting *p1,*p2;

    p1 = new (buffer) JustTesting;
    p2 = new JustTesting("Heap1",20);

    cout<<"Memory block addresses:\n"<<"buffer:"
        <<(void*)buffer<<"  heap: "<<p2<<endl;

    cout<<"Memory contents:\n";
    cout<<p1<<": ";
    p1->Show();
    cout<<p2<<": ";
    p2->Show();

    JustTesting *p3,*p4;
    p3 = new (buffer) JustTesting("Bad Idea",6);
    p4 = new JustTesting("Heap2",10);

    cout<<"Memory contents:\n";
    cout<<p3<<": ";
    p3->Show();
    cout<<p4<<": ";
    p4->Show();

    delete p2;
    delete p4;

    //delete可与常规new运算符配合使用，但不能与定位new运算符配合使用。故不能delete p1
    //所以要直接释放buffer，但是这样导致p1和p3的析构函数无法自己调用。
    //这种问题的解决方案是：显式地为使用定位new运算符创建的对象调用构造函数
    // p1->~JustTesting();
    delete []buffer;
    cout<<"Done"<<endl;
    return 0;
}