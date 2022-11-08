//
// Created by zanejins on 2022/11/8.
//

#ifndef NEW_PROJECT_DMA_H
#define NEW_PROJECT_DMA_H

#include<iostream>

//Base Class Using DMA
class baseDMA{
private:
    char * label;
    int rating;

public:
    baseDMA(const char * l = "null",int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA& rs);
    friend std::ostream& operator<<(std::ostream& os,const baseDMA& rs);
};

class lacksDMA : public baseDMA {
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char* c="blank",const char* l="null",int r=0);
    lacksDMA(const char* c,const baseDMA& rs);
    friend std::ostream & operator<<(std::ostream& os,const lacksDMA &rs);
};

class hasDMA : baseDMA {
private:
    char* style;
public:
    hasDMA(const char* s="none",const char* label="null",int r=0);
    hasDMA(const char* s,const baseDMA& rs);
    hasDMA(const hasDMA& hs); //拷贝构造
    ~hasDMA(); //析构函数
    hasDMA& operator=(const hasDMA& rs); //赋值
    friend std::ostream & operator<<(std::ostream& os,const hasDMA &rs);
};

#endif //NEW_PROJECT_DMA_H
