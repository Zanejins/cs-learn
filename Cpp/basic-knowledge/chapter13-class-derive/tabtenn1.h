//
// Created by zanejins on 2022/11/6.
//

#ifndef NEW_PROJECT_TABTENN1_H
#define NEW_PROJECT_TABTENN1_H
#include<string>
using std::string;

// simple base-class
class TableTennishPlayer{
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennishPlayer(const string & fn = "none",const string & ln = "none",bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable;}
    void ResetTable(bool v) { hasTable = v;}
};

//simple derived class
class RatedPlayer : public TableTennishPlayer {
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r=0,const string & fn="none",const string & ln="none",bool ht=false);
    RatedPlayer(unsigned int r,const TableTennishPlayer & tp);
    unsigned int Rating() const { return rating;}
    void ResetRating(unsigned int r) { rating = r;}
};
#endif //NEW_PROJECT_TABTENN1_H
