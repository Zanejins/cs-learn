#include<iostream>

template<typename T>
void ShowArray(T arr[], int n); //template A: 作为参数传递的数组是包含了要演示的数据

template<typename T>
void ShowArray(T* arr[],int n); //template B: 数据元素为指针

struct debts {
    char name[50];
    double amount;
};

int main() {
    using namespace std;
    int things[6]={12,31,103,301,310,130};
    struct debts mr_E[3] = {
        {"Ima Wolfe",2400.0},
        {"Ura Foxe",1300.0},
        {"Iby Stout",1800.0}
    };
    double* pd[3];

    // set pointers to the amount members of the structures in mr_E
    for(int i=0;i<3;i++) {
        pd[i] = &mr_E[i].amount;
    }
    cout<<"Listing Mr.E's counts of things:\n";
    // thing is an array of int
    ShowArray(things,6);               //--------------->use template A

    cout<<"Listing Mr.E's debts:\n";
    // pd is an array of pointer to double
    ShowArray(pd,3);                   //--------------->use template B

    return 0;
}

template<typename T>
void ShowArray(T arr[],int n) {
    using namespace std;
    cout<<"tmeplate A\n";
    for(int i=0;i<n;i++) 
        cout<<arr[i]<<endl;
    cout<<endl;
}

template<typename T>
void ShowArray(T* arr[],int n) {
    using namespace std;
    cout<<"tmeplate B\n";
    for(int i=0;i<n;i++) 
        cout<<*arr[i]<<endl;
    cout<<endl;
}

