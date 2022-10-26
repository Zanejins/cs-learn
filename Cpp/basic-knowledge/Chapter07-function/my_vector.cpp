#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void test();
template <class Type>
class Vector{
public:
	explicit Vector(void); //默认构造函数
	explicit Vector(int );//向量大小构造函数 防止通过隐式转换来调用这个构造函数
	explicit Vector(int, const Type&);//初始化大小，并赋初值
	virtual ~Vector(void); //析构函数
	Vector& operator = (Vector&); //操作符重载函数
    Type& operator [] (int); //inline const Type& operator [] (int) const;
    Vector<Type> operator + (const Vector<Type>&) const; 	//算术操作符重载
    Vector<Type> operator += (const Vector<Type>&) const; 	//算术操作符重载
    bool operator == (const Vector<Type>&) const; 	//算术操作符重载
    bool operator != (const Vector<Type>&) const; 	//算术操作符重载
    Type& operator[] (const Vector<Type>&) const; 	//算术操作符重载
    friend std::ostream& operator<<(std::ostream& out, const Vector<Type>& V); //输出运算符重载
    friend std::istream& operator>>(std::istream& in, const Vector<Type>& V); //输出运算符重载
    inline int get_size(void) const;
    int size; //向量大小
    Type *data;  // 指向数据的指针
};

int main() {
    test();
}
template <class Type>  //默认构造函数
Vector<Type>::Vector(void)
{
   size = 0;
   data = NULL;
}

//维度构造
template <class Type> 
Vector<Type>::Vector(int new_size)
{
   size = new_size;
   data = new Type[new_size];
}
 
//创建一个大小为new_size的向量，并用类型为Type的值给向量赋初值
template <class Type>
Vector<Type> ::Vector(int new_size, const Type& value) 
{  
   size = new_size;
   data = new Type[new_size];
   
   for(int i = 0; i < size; i++)
   {
      data[i] = value;
   }
}
 
//析构函数
template <class Type> 
Vector<Type>::~Vector(void)
{
   if(data != NULL)
   {
      delete[](data);
   }
}
//赋值运算符重载，将一个向量赋给另一个向量
template <class Type>
Vector<Type>& Vector<Type>::operator= (Vector<Type>& other_vector)
{
   if(this != &other_vector) // other vector
   {
      if(size != other_vector.get_size()) // other size
      {
         if(data != NULL)
         {
            delete [] (data);
         }
 
         size = other_vector.size;
 
         data = new Type[size];
      }
 
      for(int i = 0; i < size; i++)
      {
         data[i] = other_vector[i];
      }
   }
   return(*this);
}
 
//返回向量索引为i的值
template <class Type>
Type& Vector<Type>::operator [] (int i) 
{
 
   if(size == 0)
	  throw "vector is null";
   else if(i<0 || i>=size) 
      throw "index is out of range";
   else 
      return data[i] ;
}
 
template <class Type> 
std::ostream &operator<<(std::ostream &out,Vector<Type>& V)  
{  
	
	for(int i=0;i<V.size;i++)  
    {  
	   out<<V.data[i]<<" ";  
       if((i+1)%10==0)  
		   out<<endl;  
    }  
	return out;  
}  

template <class Type> 
std::istream &operator>>(std::istream &in,Vector<Type>& V)  
{  
	for(int i=0;i<V;i++)  
    {  
        in>>V.data[i];
    }  
	return in;  
}  


 
//一个向量加上另一个向量
template <class Type>
Vector<Type> Vector<Type>::operator+ (const Vector<Type>& other_vector) const
{       
   int other_size = other_vector.get_size();
   if(other_size != size)
        throw "size of vectors must be same";
 
   Vector<Type> sum(size);
  
   for(int i = 0; i < size; i++)
   {
      sum[i] = data[i] + other_vector.data[i];
   }
   return sum;
}
 

template <class Type>
Vector<Type> Vector<Type>::operator += (const Vector<Type>& other_vector) const
{       
   Vector<int> temp=(*this) + other_vector;
   return temp;
}

template <class Type>
bool Vector<Type>::operator == (const Vector<Type>& other_vector) const
{       
    int other_size = other_vector.get_size();
    if(other_size != size)
         return false;
    for(int i=0;i<size;i++) {
        if(data[i]!=other_vector.data[i]) return false;
    }
    return true;
}

template <class Type>
bool Vector<Type>::operator != (const Vector<Type>& other_vector) const
{       
   int other_size = other_vector.get_size();
    if(other_size != size)
         return true;
    for(int i=0;i<size;i++) {
        if(data[i]!=other_vector.data[i]) return true;
    }
    return false;
}
template <class Type>
inline int Vector<Type>::get_size(void) const
{
   return size;
}
 

 void test() {
    // 测试构造函数
    Vector<int> v1(4,1);
    cout<<"after v1(4,1) ,v1: "<<v1<<endl;    
    //测试[]运算符
    cout<<"v1 is "<<v1<<"v1[1] is "<<v1[1]<<endl;
    //测试拷贝构造函数
    Vector<int> v2(v1);
    cout<<"after v2(v1), v2: "<<v2<<endl;
    //测试赋值号
    Vector<int> v3=v1;
    cout<<"after v3=v1, v3 = "<<v3<<endl;
    //测试+
    try {
      Vector<int> v4(3,1);
      Vector<int> v5(3,2);
      Vector<int> v6(4,1);
      Vector<int> v7=v4+v5;  //没有异常
      cout<<"v4 = "<<v4<<" v5 = "<< v5 <<" v4 + v5 = " << v7<<endl;
    
      Vector<int> v8=v4+v6; //有异常
      cout<<"v4 = "<<v4<<" v6 = "<< v6 <<" v4 + v6 = " << v8<<endl;
    }catch(const char *s) {
      cout<<s<<endl;
    }
    //测试+=
    try {
      Vector<int> v4(3,1);
      Vector<int> v5(3,2);
      Vector<int> v6(4,1);
      Vector<int> v7=v4+v5; 
      v4+=v5;  //没有异常
      cout<<"v4 = "<<v4<<" v5 = "<< v5 <<" after v4 + = v5, v4 " << v7<<endl;
    
      v4+=v6; //有异常
      cout<<"v4 = "<<v4<<" v6 = "<< v6 <<"  after v4 + = v5, v4 " << v4<<endl;
    }catch(const char *s) {
      cout<<s<<endl;
    }
    //测试==
      Vector<int> v9(3,1);
      Vector<int> v0(3,2);
      bool res=v9==v0;
      cout<<"v9 = "<<v9<<" v0 = "<<v0<<" v9 == v0: "<<res<<endl;

    //测试！=
      res= v9!=v0;
      cout<<"v9 = "<<v9<<" v0 = "<<v0<<" v9 == v0: "<<res<<endl;

    //测试get_size
    cout<<"v9 = "<<v9<<" v9.size = "<<v9.get_size()<<endl;
 }