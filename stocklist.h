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

public:
    stocklist();
    void addtoList(stockNode*);
    bool addusingFile(string filename);
    stockNode* mid_stock();
    stockNode* split_list();
    void print_list();

};


#endif //LAB3_STOCKLIST_H
