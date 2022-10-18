/*************************************************************************
	> File Name: calling.cpp
	> Author: zanejins
	> Mail: zanejins@163.com 
	> Created Time: 2022年10月18日 星期二 19时28分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
void simple();

int main(){
	cout<<"main() will call the simple() function:\n";
	simple();
	cout<<"main() is finished with the simple() function.\n";
	return 0;
}

void simple() {
cout<<"I am but a simple function.\n";
}
