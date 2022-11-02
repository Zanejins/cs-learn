//
// Created by zanejins on 2022/11/2.
//

#ifndef NEW_PROJECT_STONEWT_H
#define NEW_PROJECT_STONEWT_H

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
};
#endif //NEW_PROJECT_STONEWT_H
