/*************************************************************************
	> File Name: lotto.cpp
	> Author: zanejins
	> Mail: zanejins@163.com 
	> Created Time: 2022年10月18日 星期二 20时08分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

long double probability(unsigned numbers,unsigned picks);

int main() {
	double total,choices;

	cout<<"Enter the total number of choices on the game card and the number of picks allowed:\n";
    while((cin>>total>>choices)&&choices<=total) {
		cout<<"You have one chance in ";
		cout<<probability(total,choices);
		cout<<" of winning.\n";
		cout<<"Next two numbers(q to quit):";
	}
	cout<<"bye\n";
	return 0;
}

long double probability(unsigned numbers,)
