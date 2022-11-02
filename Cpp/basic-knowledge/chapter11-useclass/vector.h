//
// Created by zanejins on 2022/11/2.
//

#ifndef NEW_PROJECT_VECTOR_H
#define NEW_PROJECT_VECTOR_H

#include<iostream>

namespace VECTOR
{
    class Vector{
    public:
        enum Mode {RECT,POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1,double n2,Mode form = RECT);
        void reset(double n1,double n2,Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}
        double polar_mode(); //set mode to POL
        double rect_mode(); //set mode to RECT

        //operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n,const Vector & a);
        friend std::ostream& operator<<(std::ostream &os,const Vector & v);
    };
}
#endif //NEW_PROJECT_VECTOR_H
