#include<iostream>

char* buildstr(char c,int n);

int main() {
    using namespace std;

    int times;
    char ch;
    ch='V';
    times=46;
    char *ps = buildstr(ch,times);

    cout<<ps<<endl;
    //当字符串不要需要时,使用delete释放该字符串占用的内存。然后,将ps指向为下一个字符串字符串分配的内存块，然后
    //释放它们。这种设计的缺点是，程序员必须技术使用delete.
    delete [] ps; // free memory
    ps = buildstr('+',20);

    cout<<ps<<"-DONE-"<<ps<<endl;
    delete []ps;
    return 0; 
}

char* buildstr(char c,int n) {
    //要创建包含n个字符的字符串，需要能够存储n+1个字符的存储空间，以便能够存储空值字符
    char * pstr = new char[n+1];
    pstr[n]='\0';
    while(n--) {
        pstr[n]=c;
    }
    return pstr;
    //注意pstr的作用域为buildstr函数内，因此该函数结束时候，pstr（而不是字符串）使用的内存将被释放。
    //但是由于函数返回了pstr的值，因此程序仍可以通过main中的指针ps来访问新建的字符串
}