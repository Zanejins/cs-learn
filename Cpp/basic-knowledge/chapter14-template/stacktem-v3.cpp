#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"
using std::cin;
using std::cout;


int main() {
    //模板类型使用了指针类型，将string--->char* po=new char[40];
    /*
     * 这为输入的字符串分配了空间，另外po是变量，因此与pop()的代码
     * 兼容。然而，这里将会遇到最基本的问题：只有一个pop变量，该变量
     * 总是指向相同的内存单元。确实，在每当读取新字符串时候，
     * 内存的内容都将发生变化，但每次之行压入操作时，加入到stack中的
     * 地址都相同。因此，对stack执行弹出操作时，得到的地址总是相同的，
     * 它总是指向读入的最后一个字符串。具体地说，stack并没有保存每一个新字符串，
     * 因此没有任何用途。
     */
    Stack<char*> st;
    char ch;
    char* po = new char[40];

    cout<<"Please enter A to add a purchase order.\n";
    cout<<"P to process a PO, or Q to quit.\n";

    while(cin>>ch&&std::toupper(ch)!='Q') {
        while(cin.get()!='\n')
            continue;

        if(!std::isalpha(ch))
        {
            cout<<'\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout<<"Enter a PO number to add: ";
                cin>>po;
                if(st.isfull())
                    cout<<"stack already full.\n";
                else
                    st.push(po);
                break;

            case 'p':
            case 'P':
                if(st.isempty())
                    cout<<"stack already empty\n";
                else{
                    st.pop(po);
                    cout<<"PO # "<<po<<" popped\n";
                    break;
                }
        }
        cout<<"Please enter A to add a purchase order.\n";
        cout<<"P to process a PO, or Q to quit.\n";
    }

    cout<<"Bye\n";
    return 0;
}

