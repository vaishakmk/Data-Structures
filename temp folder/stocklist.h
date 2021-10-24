//
// Created by Vaishak Kallampad on 10/3/21.
//

#ifndef LAB3_STOCKLIST_H
#define LAB3_STOCKLIST_H
#include "stock.h"

class stocklist {
private:
    stockNode *head;
    stockNode *tail;
    int length = 0;

public:
    stocklist();
    int getLength();
    void addtoListbegin(stockNode*);
    void addtoListend(stockNode*);
    bool addstock(stock,int ch);
    bool addusingFile(string filename,int ch);
    stockNode* mid_stock();
    void split_list();
    void print_list();

};


#endif //LAB3_STOCKLIST_H
