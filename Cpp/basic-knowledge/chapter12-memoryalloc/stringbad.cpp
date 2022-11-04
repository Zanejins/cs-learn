#include<cstring>
#include "stringbad.h"

using std::cout;

/* 类静态成员的初始化
 * 这条语句将静态成员num_strings的值初始化为0，请注意不能在类声明中初始化静态成员变量
 * 这是因为声明描述了如何分配内存，但并不分配内存。对于静态类成员，可以在类声明之外使用单独的语句进行初始化
 * 这时因为静态类成员是单独存储的，而不是对象的组成部分。请注意，初始化语句指出了类型，并使用了作用域运算符，但没有
 * 使用关键字static
 *
 * 总结：静态数据成员在类声明中声明，在包含类方法的文件中初始化。初始化时使用作用域
 * 运算符来指出静态成员所属的类。但如果静态成员是整形或者枚举类const，则可以在类声明中
 * 初始化。
 */
int StringBad::num_strings = 0;

//class methods
//construct StringBad from C string
StringBad::StringBad(const char *s) {
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    num_strings++;
    cout<<num_strings<<":\""<<str
        <<"\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str,"C++");
    num_strings++;
    cout<<num_strings<<":\""<<str
        <<"\" object created\n";
}

StringBad::~StringBad() {
    cout<<"\""<<str<<"\" object deleted, ";
    --num_strings;
    cout<<num_strings<<" left\n";
    delete []str;
}
//如果类中博涵了使用new初始化的指针成员，应当定义一个复制构造函数
//以复制指向的数据，而不是指针，这被称为深度复制。复制的另一种形式只是复制指针值。
//浅复制仅浅浅地复制指针信息，而不会深入挖掘以复制指针引用的结构。
StringBad::StringBad(const StringBad &st) {
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    cout<<num_strings<<":\""<<str
        <<"\" object created\n";
}

StringBad & StringBad::operator=(const StringBad &st) {
    if(this == &st) {
        return *this;
    }
    delete []str;
    len =st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    return *this;
}
std::ostream & operator<<(std::ostream & os,const StringBad & st) {
    os << st.str;
    return os;
}
