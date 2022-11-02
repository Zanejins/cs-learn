#include "stonewt.h"
#include<iostream>

/* 自动转换
 * 只接受一个参数的构造函数定义了从参数类型到类类型的转换，
 * 如果使用关键字explicit限定了这种钩爪函数，则只能用户显示转换，否则也可以用于隐式转换。
 * 如果没有使用关键字explicit，则在下列场景将发生隐式转换：
 *   1. 将Stonewt对象初始化为double值时
 *   2. 将double值赋值给Stonewt对象时
 *   3. 将double值传递给接收Stonewt参数的函数时候
 *   4. 返回值被声明为Stonewt的函数试图返回double值时
 *   5. 在上述任意一种情况下，使用可以转换为double类型的内置类型时候
 */
Stonewt::Stonewt(double lbs) {
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn +lbs -int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds =stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {

}

void Stonewt::show_stn() const {
   std::cout<<stone<<"stone, "<<pds_left<<"pounds\n";
}

void Stonewt::show_lbs() const {
    std::cout<<pounds<<" pounds\n";
}
