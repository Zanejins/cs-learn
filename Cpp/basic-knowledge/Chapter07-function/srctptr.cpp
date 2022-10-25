#include<iostream>
#include<cmath>
using namespace std;

struct rect {
    double x;
    double y;
};

struct polar {
    double distance;
    double angle;
};

void show_polar(const polar *dapos) {
    using namespace std;

    const double Rad_to_deg = 57.29577951;

    cout<<"distance = " << dapos->distance;
    cout<<", angle = "<<dapos->angle * Rad_to_deg;
    cout<<" degrees\n";
}

polar rect_to_polar(const rect *xypos) {
    polar answer;
    answer.distance= sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
    answer.angle = atan2(xypos->y,xypos->x);
    return answer;
}
int main() {
    rect rplace;
    polar pplace;

    cout<<"Enter the x and y values: ";
    // cin是istream类的一个对象。抽取运算符（>>）被设计成是的cin>>replace.x也是一个istream对象。
    //使用cin>>replace.x时候，程序将调用一个函数，该函数返回一个istream只。因此整个while循环的测试表达式
    //的最终结果为cin,而cin被用于测试表达式中时，将根据输入是否成功，被转换为bool值。
    while(cin>>rplace.x>>rplace.y) {
        pplace = rect_to_polar(&rplace);
        show_polar(&pplace);
        cout<<"Next two numbers (q to quit):";
    }
    cout<<"Done.\n";
    return 0;
}