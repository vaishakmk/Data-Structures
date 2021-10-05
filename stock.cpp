//
// Created by Vaishak Kallampad on 10/3/21.
//

#include "stock.h"

using namespace std;



    ostream &operator<<(ostream &os, const stock &s1) {
        os << s1.symbol << " " << s1.cost << " " << s1.num;
        return os;
    }

    istream &operator>>(istream &is, stock &s1) {
        char ch;
        is >> s1.symbol >> s1.cost >> s1.num;
        return is;
    }

    stock::stock(string s, int c, int n) {
        setstock(s,c,n);
    }

    void stock::setstock(string s, double c, int n) {
        symbol = s;
        cost = c;
        num = n;
    }


