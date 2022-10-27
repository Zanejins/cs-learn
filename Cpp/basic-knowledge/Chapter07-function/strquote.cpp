#include<iostream>

using namespace std;

string version1(const string& s1,const string & s2);
const string& version2(string &s1,const string & s2);
const string& version3(string &s1,const string & s2);

int main() {
    string input;
    string copy;
    string result;
    cout<<"Enter a string:";
    getline(cin,input);

    copy = input;
    cout << "Your string as entered : "<<input<<endl;
    
    //思考：程序如何能接受将char指针赋值给string引用呢？
    /*
     这里有两点需要说明。首先，string类定义了一种char*到string的转换功能，这使得可以使用C-风格字符串来初始化string对象，
     其次是本章前面讨论过的类类型为congst引用的形参的一个属性。假设实参的类型与引用类型不匹配，但可以被转换为引用类型，程序将创建一个正确类型的临时变量，
     使用转换后的实参值来初始化它，然后传递一个指向该临时变量的引用。
     这种属性的结果是，如果形参类型为const string &, 在调用函数时，使用的实参可以是string对象或者C-风格字符串，如用引号括起来的字符串常量、
     以空字符串结尾的char数组或指向char的指针变量。
    */
    result = version1(input,"***");
    cout<<"Your string enhanced: "<<result<<endl;
    cout<<"Your original string: "<<input<<endl;

    result = version2(input,"###");
    cout<<"Your string enhanced: "<<result<<endl;
    cout<<"Your original string: "<<input<<endl;

    cout<<"Resetting original string:\n";
    input = copy;
    result = version3(input,"@@@");
    cout<<"Your string enhanced: "<<result<<endl;
    cout<<"Your original string: "<<input<<endl;

    return 0;

}

string version1(const string & s1,const string & s2) {
    string temp;

    temp = s2 + s1 +  s2;

    return temp;
}

const string & version2(string & s1,const string & s2) {
    s1 = s2 + s1 + s2;
    return s1; //safe to return reference passed to function.
}

const string & version3(string & s1,const string & s2) {
    string temp;

    temp = s2 + s1 + s2;

    return temp; //unsaft to return reference to local variable
}

