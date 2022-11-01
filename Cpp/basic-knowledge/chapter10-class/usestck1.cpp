#include<iostream>
#include "stock01.h"

int main(){
    {
        using std::cout;
        cout<<"Using constructors to create new objects\n";
        Stock stock1("NaoSmart",12,20.0);
        stock1.show();
        Stock stock2 = Stock("Boffo Objects",2,2.0);
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout<<"Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        cout<<"Using a constructor to reset to an object\n";
        //让构造程序创建一个新的、临时的对象，然后将其内容赋值给stock1来实现。随后程序调用析构函数，以删除该临时对象
        stock1 = Stock("Nifty Foods",10,50.0);
        cout<<"Revised stock1:\n";
        stock1.show();
        cout<<"Done\n";
    }
    return 0;
}
