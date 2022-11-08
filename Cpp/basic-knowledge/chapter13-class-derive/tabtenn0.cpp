//
// Created by zanejins on 2022/11/6.
//
#include"tabtenn0.h"
#include<iostream>

//为什么使用初始化列表呢？
/*
 *  TableTennishPlayer::TableTennishPlayer(const std::string &fn, const std::string &ln, bool ht) {
        firstname = fn;
        lastname = ln;
        hasTable = ht;
    }
    如果不采用初始化列表，而采用上述方式，这将首先为firstname调用string的默认构造函数，再调用string的赋值运算符将firstname设置为fn，
    但是初始化列表语法可以减少一个步骤，他直接使用string的复制构造函数将firstname初始化为fn.
 */
TableTennishPlayer::TableTennishPlayer(const std::string &fn, const std::string &ln, bool ht) : firstname(fn),lastname(ln),hasTable(ht){

}

void TableTennishPlayer::Name() const {
    std::cout<<lastname<<", "<<firstname;
}

