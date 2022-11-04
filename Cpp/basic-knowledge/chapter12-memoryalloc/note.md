
## 在构造函数中使用new时应注意的事项

1. 如果在构造函数中使用new来初始化指针成员，则应在析构函数中使用delete
2. new和delete必须相互兼容，new对应于delete,new[] 对应于delete[]
3. 如果有多个构造函数，则必须以相同的方式使用new，要么都带中括号，要么都不带。因为只有
   一个构造函数，所有的构造桉树都必须与它兼容。

4. 应该定义一个复制构造函数，通过深度复制将一个对象初始化为另一个对象。通常，这种
   构造函数与下面类似
   String::String(const String& st) {
     num_string++;
     len = st.len;
     str = new char[len+1];
     std::strcpy(str,st.str);
   }

5. 应该定义一个赋值运算符，通过深度复制将一个对象复制给另一个对象。通常，该类方法与下面类似：
    //overload operator methods
    String & String::operator=(const String &st) {
        if(this == &st) return *this;
        delete []str;
        len= st.len;
        str = new char[len+1];
        std::strcpy(str,st.str);
        return *this;
    }


## 使用new初始化对象
通常，如果Class_name是类，value的类型为Type_name, 则下面的语句：
Class_name *pclass = new Class_name(value);

将调用如下构造函数Class_name(Type_name)，这里可能会有一些琐碎的转换

## 在下列情况下析构函数将被调用
1. 如果对象是动态变量，则当执行完定义该对象的程序块时，将调用该对象的析构函数。
2. 如果对象是静态变量，则在程序结束时将调用对象的析构函数。
3. 如果对象是用new创建的，则仅当您显式使用delete删除对象时，其析构函数才会被调用。


