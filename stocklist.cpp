//
// Created by Vaishak Kallampad on 10/3/21.
//
#include "stock.h"
#include "stocklist.h"
#include<fstream>
#include<sstream>

stocklist::stocklist() {
    head = NULL;
    tail = NULL;
}

int stocklist::getLength() {
    return this->length;
}

void stocklist::addtoList(stockNode* s) {
    if(head==NULL)
    {
        s->prev=s->next=NULL;
        head=tail=s;
        this->length = this->length + 1;
        return;
    }
    else{
        s->next= head;
        s->prev=NULL;
        s->next->prev = s;
        head = s;
        this->length = this->length + 1;
        return;
    }
}

bool stocklist::addusingFile(string filename) {
    ifstream fin;
    string ss;
    stock s; string sym; double co;int no;
    fin.open(filename.c_str());
    if (!fin.is_open())  {cout<<"file error";cerr << "Error: " << strerror(errno);return(false);}// error checking needed
    while (!fin.eof()){
            getline(fin,ss);
            stringstream(ss)>>sym >> co >> no;
            s.setstock(sym,co,no);
            stockNode *sp = new stockNode();
            sp->stk=s;
            addtoList(sp);
        }
fin.close();
return(true);
}

bool stocklist::addstock(stock st) {
    stockNode *sp = new stockNode();
    sp->stk=st;
    addtoList(sp);
    return(true);
}


void stocklist::print_list()
{
    cout << "List ~> ";
    stockNode *st = head;
    while (st != NULL) {
        cout << "["<<st->stk<< "] ===> ";
        st = st->next;
    }
    cout<<endl;
    return;
}

stockNode* stocklist::mid_stock() {
    int mid = 0;
    if (this->length == 0) {
        cout << "no items in the list" << endl;
        return NULL;
    }

    if (this->length == 1) {
        cout << "Only one item in the list. Mid = 0"<<endl;
        return NULL;
    }
    stockNode *slow=head, *fast=head;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast!=NULL) fast=fast->next;
        mid = mid+1;
    }
    cout<< "The middle stock is => ["<<slow->stk <<"] => located at the "<<mid<<"th position"<<endl;
    return slow;
}

stockNode* stocklist::split_list() {
    if (this->length == 0) {
        cout << "No items in the list. Cannot split" << endl;
        return NULL;
    }

    if (this->length == 1) {
        cout << "Only one item in the list. Cannot Split"<<endl;
        return NULL ;
    }
    stockNode* mid = this->mid_stock();
    stocklist sl2;
    sl2.head = mid; sl2.tail=tail;
    this->tail = mid->prev;
    mid->prev->next=NULL;
    mid->prev=NULL;
    cout<<"First list"<<endl;
    this->print_list();
    cout<<"Second list"<<endl;
    sl2.print_list();
    return mid;
}