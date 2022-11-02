/* C++为类提供了下面的类型转换
 *  1. 只有一个参数的类构造函数用于将类型与该参数相同的值转换为类类型
 *     可以使用explicit防止隐式转换，而只允许显示转换
 *  2. 被称为转换函数的特殊类成员运算符函数，用于将类对象转换为其他类型。转换函数
 *     是类成员，没有返回类型，没有参数、名为operator typeName(),其中typename
 *     是对象将被转换成的类型。将类对象赋给typename变量或将其强制转换为typename类型时候，
 *     该函数将自动被调用。
 */
#ifndef NEW_PROJECT_STONEWT1_H
#define NEW_PROJECT_STONEWT1_H

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};  //pound per stone
    int stone; //whole stones
    double pds_left; //fractional pounds
    double pounds; //entire weight in pounds
public:
    Stonewt(double lbs);
    Stonewt(int stn,double lbs);
    Stonewt();
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;
    /* 如何创建转换函数呢？
     * A：operator typename();
     * 注意以下几点：
     *    1. 转换函数必须是类方法
     *    2. 转换函数不能指定返回类型
     *    3. 转换函数不能有参数
     */
    //conversion functions
    operator int() const;
    operator double() const;
};
#endif //NEW_PROJECT_STONEWT1_H
