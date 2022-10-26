#include<iostream>

using namespace std;

double cube(double a);
double refcube(double &ra);

int main() {
    double x = 3.0;
    cout << cube(x);
    cout <<" = cube of "<<x<<endl;

    cout << refcube(x);
    cout <<" = cube of "<<x<<endl;

    double side =3.0;
    double * pd =&side;
    double & rd = side;

    long edge =5L;
    double lens[4] = {2.0 , 5.0 , 10.0 , 12.0};
    double c1 = refcube(side);
    double c2 = refcube(lens[2]);
    double c3 = refcube(rd);
    double c4 = refcube(*pd);
    double c5 = refcube(edge);  //实参的类型不正确，但是可以转化成正确的类型，因此，临时变量ra
    double c6 = refcube(7.0);   //实参的类型正确，但是不是左值，因此，临时变量
    double c7 = refcube(side + 10.0);  //实参的类型正确，但是不是左值，因此，临时变量
}

double cube(double a) {
    a *= a * a;
    return a;
}

double refcube(const double &ra) {
    return ra * ra * ra;
}