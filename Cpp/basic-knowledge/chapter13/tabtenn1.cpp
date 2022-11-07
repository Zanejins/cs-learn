#include<iostream>
#include "tabtenn1.h"

TableTennishPlayer::TableTennishPlayer(const std::string &fn, const std::string &ln, bool ht) : firstname(fn),lastname(ln),hasTable(ht) {

}

void TableTennishPlayer::Name() const {
    std::cout<<lastname<<" , "<<firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennishPlayer(fn,ln,ht){
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennishPlayer &tp) : TableTennishPlayer(tp),rating(r){

}


