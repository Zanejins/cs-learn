//
// Created by zanejins on 2022/11/19.
//

#ifndef NEW_PROJECT_STACKTP1_H
#define NEW_PROJECT_STACKTP1_H

template<class Type>
class Stack
{
private:
    enum {SIZE = 10};
    int stacksize;
    Type* items;
    int top;

public:
    explicit Stack(int ss=SIZE);
    Stack(const Stack &st);
    ~Stack() { delete []items;}
    bool isempty() { return top==0; }
    bool isfull() { return top==stacksize;}
    bool push(const Type& item);
    bool pop(Type & item);
    Stack & operator=(const Stack& st);
};

template<class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0) {
    items = new Type[stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack<Type> &st) {
    stacksize = st.stacksize;
    top = st.top();
    items = new Type[stacksize];
    for(int i=0;i<top;i++)
        items[i] = st.items[i];
}


template<class Type>
bool Stack<Type>::push(const Type &item) {
    if(top<stacksize)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}


template<class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top>0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

//原型将赋值运算符函数的返回类型声明为Stack引用，
// 而实际的模板函数定义将类型定义Stack<Type>。
//前者是后者的缩写，但智能在类中使用，即可在模板声明
//或模板函数定义使用Stack。

template<class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &st) {
    if(this == &st)
        return *this;
    delete []items;

    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i=0;i<top;i++)
        items[i] = st.items[i];
    return *this;
}
#endif //NEW_PROJECT_STACKTP1_H
