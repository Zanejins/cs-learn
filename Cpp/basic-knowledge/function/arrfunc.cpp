/*************************************************************************
	> File Name: arrfunc.cpp
	> Author: zanejins
	> Mail: zanejins.com 
	> Created Time: 2022年10月19日 星期三 19时42分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int Max = 5;
int fill_array(double ar[],int limit) {
	double temp;
	int i;
	for(i=0;i<limit;i++) {
		cout<<"Enter value #"<<(i+1)<<": ";
		cin>>temp;
		if(!cin) { //bad input
			cin.clear();
			while(cin.get()!='\n') 
				continue;
			cout<<"Bad input; input process terminated.\n";
			break;
		}
		else if(temp<0) {
			break;
		}
		ar[i]=temp;
	}
	return i;
}

void show_array(const double ar[],int n) {
	for(int i=0;i<n;i++) {
		cout<<"Property #"<<(i+1)<<": $"<<ar[i]<<endl;
	}
}

void revalue(double r,double ar[],int n){
	for(int i=0;i<n;i++) {
		ar[i]*=r;
	}
}
int main() {
	double properties[Max];

	int size = fill_array(properties,Max);

	show_array(properties,size);

	if(size > 0) {
		cout<<"Enter revaluation factor: ";
		double factor;
		while(!(cin>>factor)) { //bad input
			cin.clear();
			while(cin.get()!='\n') 
				continue;
			cout<<"Bad input; Please enter a number:";
		}
		revalue(factor,properties,size);
		show_array(properties,size);
	}
	cout<<"Done."<<endl;
	cin.get();
	cin.get();
}
