/*************************************************************************
	> File Name: protos.cpp
	> Author: zanejins
	> Mail: zanejins@163.com 
	> Created Time: 2022年10月18日 星期二 19时44分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

void cheers(int);
double cube(double x);

int main() {
	using namespace std;

	cheers(5);
	cout<<"Give me a number: ";
	double side;
	cin>>side;

	double volume = cube(side);
	cout<<"A "<<side<<"-foot cube has a volume of ";
	cout<<volume<<"cubic feet.\n";
	cheers(cube(2));
	return 0;
}

void cheers(int x) {
	using namespace std;
	for(int i=0;i<x;i++) {
		cout<<"Cheers!";
	}
	cout<<endl;
}

double cube(double x) {
	return x*x*x;
}
