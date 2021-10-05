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

void stocklist::addtoList(stockNode* s) {
    if(head==NULL)
    {
        s->prev=s->next=NULL;
        head=tail=s;cout<<"Node successfully added"<<endl;
        return;
    }
    else{
        s->next= head;
        s->prev=NULL;
        s->next->prev = s;
        head = s;
        return;
    }
}

bool stocklist::addusingFile(string filename) {
    ifstream fin;
    string ss;
    stock s; string sym; int co,no;
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



void stocklist::print_list()
{
    cout << "List ~> ";
    stockNode *st = head;
    while (st != NULL) {
        cout << st->stk<< " ===> ";
        st = st->next;
    }
    cout<<endl;
    return;
}

stockNode* stocklist::mid_stock() {
    stockNode *slow=head, *fast=head;
    int mid = 0;
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast!=NULL) fast=fast->next;
        mid = mid+1;
    }
    cout<< "The middle stock is => "<<slow->stk<<endl;
    cout<<"It is at "<<mid<<"th position"<<endl;
    return slow;
}

stockNode* stocklist::split_list() {
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