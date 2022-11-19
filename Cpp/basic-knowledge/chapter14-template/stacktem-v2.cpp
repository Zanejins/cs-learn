#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"
using std::cin;
using std::cout;


int main() {
    //模板类型使用了指针类型，将string--->char po[40];
    Stack<char*> st;
    char ch;
    char po[40];

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

