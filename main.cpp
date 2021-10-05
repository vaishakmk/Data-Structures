#include "stock.h"
#include "stocklist.h"
#include <iostream>
using namespace std;

int main() {
    stock s1("Apple",1000,50),s2("FB",50);
    stock s3;
    cout<<s3<<endl;
    cout<<s2<<endl;
    cout<<s1<<endl;
    stocklist sl = stocklist();
    sl.addstock(s2);
    sl.addstock(s1);
    sl.print_list();
    sl.addusingFile("/Users/vaishakkallampad/Desktop/PROGRAMS/lab3/stocks.txt");
    sl.print_list();
    sl.mid_stock();
    sl.split_list();

}
