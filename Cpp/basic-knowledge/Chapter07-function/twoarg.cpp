/*************************************************************************
	> File Name: twoarg.cpp
	> Author: zanejins
	> Mail: zanejins@163.com 
	> Created Time: 2022年10月18日 星期二 20时00分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

void n_chars(char,int);

int main() {
	int times;
	char ch;

	cout<<"Enter a character: ";
	cin >> ch;
	while(ch!='q') {
		cout<<"Enter an integer:";
		cin>>times;
		n_chars(ch,times);
		cout<<"\nEnter another character or press the q-key to quit: ";
        cin>>ch;
	}
	cout<<"The value of time is "<<times<<".\n";
	cout<<"Bye\n";
	return 0;
}

void n_chars(char c,int n) {
	while(n-->0) {
		cout<<c;
	}
}
