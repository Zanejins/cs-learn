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
    JustTesting(const string &s = "Just Testing",int n=0) {
        words = s;
        number = n;
        cout<<words<<" constructe\n";
    }

    ~JustTesting(){
        cout<<words<<" destroyed\n";
    }
    void Show() const {
        cout<<words<<", "<<number<<endl;
    }
};

int main() {
    char * buffer = new char[BUF];
    JustTesting *p1,*p2;

    p1 = new (buffer) JustTesting;
    p2 = new JustTesting("Heap1",20);

    cout<<"Memory block address:\n"<<"buffer: "
        <<(void*) buffer <<"   heap: "<<p2<<endl;

    cout<<"Memory contents:\n";
    cout<<p1<<": ";
    p1->Show();
    cout<<p2<<": ";
    p2->Show();

    JustTesting *p3,*p4;
    p3= new (buffer+ sizeof(JustTesting)) JustTesting("better idea",6);
    p4= new JustTesting("Heap2",10);

    cout<<"Memory contents:\n";
    cout<<p3<<": ";
    p3->Show();
    cout<<p4<<": ";
    p4->Show();

    delete p2;
    delete p4;
    // 注意：对于使用定位new运算符创建的对象，应以与创建顺序相反的顺序进行删除，
    p3->~JustTesting();
    p1->~JustTesting();
    delete []buffer;
    cout<<"Done"<<endl;
    return 0;

}