#include<iostream>
#include "stonewt1.h"
using std::cout;

int main() {
    Stonewt popins(9,2.8);
    double p_wt = popins;
    cout<<"Convert to double => ";
    cout<<"Popins: "<<p_wt<<" pounds.\n";
    cout<<"Convert to int => ";
    cout<<"Poppins: "<<int(popins)<<" pounds.\n";
    return 0;
}
