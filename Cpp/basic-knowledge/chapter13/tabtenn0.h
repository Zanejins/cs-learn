//
// Created by zanejins on 2022/11/6.
//

#ifndef NEW_PROJECT_TABTENN0_H
#define NEW_PROJECT_TABTENN0_H
#include<string>
using std::string;

class TableTennishPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennishPlayer(const string& fn = "none",const string& ln="none",bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable;}
    void ResetTable(bool v) { hasTable =  v;};
};
#endif //NEW_PROJECT_TABTENN0_H
