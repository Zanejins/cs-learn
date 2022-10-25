#include<iostream>
using namespace std;

void countdown(int n);
int main() {
    countdown(4);
    return 0;
}

void countdown(int n) {
    std::cout<<"Counting down ..."<<n<<"( n at "<<&n<<")"<<std::endl;

    if(n>0) {
        countdown(n-1);
    }
    std::cout<<n<<" Kaboom!"<<"          ( n at "<<&n<<")"<<std::endl;
}