//
// Created by Vaishak Kallampad on 10/3/21.
//

#ifndef LAB3_STOCK_H
#define LAB3_STOCK_H
#include<iostream>
#include<sstream>

using namespace std;

class stock {

    friend ostream& operator<<(ostream&,const stock&);
    friend istream& operator>>(istream&,stock&);

public:
    stock(string s="",int c=0 ,int n=0 );
    void setstock(string s="",double c=0 ,int n=0 );

private:
    string symbol;
    double cost;
    int num;
};

class stockNode {
public:
    stock stk;
    stockNode *prev;
    stockNode *next;

};

#endif //LAB3_STOCK_H
