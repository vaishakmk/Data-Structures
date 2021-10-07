#include "stock.h"
#include "stocklist.h"
#include <iostream>
using namespace std;

int main() {
    stock s1("TTM",22.34,50),s2("FB",333.64);
    stock s3(s1);
    cout<<s3<<endl;
    //OUTPUT : TTM 22 50
    cout<<s2<<endl;
    //OUTPUT : FB 333 0
    cout<<s1<<endl;
    //OUTPUT : TTM 22 50

    int choice;//Entering choice to add at front or back of Linked List. By default, it will add at back.
    cout<<"To add at head of linked list enter 1\n"
          "To add at tail of linked list enter 2 \n";
    cin>>choice;

    stocklist sl = stocklist();//creating linked list
    sl.addstock(s2,choice);//adding individual stocks to the Linked List
    sl.addstock(s1,choice);

    sl.print_list();//printing out the linked list
    //OUTPUT : List : Head ===> [FB 333 0]  ===> [TTM 22 50]

    sl.addusingFile("/Users/vaishakkallampad/Desktop/PROGRAMS/lab3/stocks.txt",choice);//adding from files

    sl.print_list();
    //OUTPUT : List : Head ===> [FB 333 0]  ===> [TTM 22 50]  ===> [AAPL 150 500]  ===> [AMZN 189 200]  ===> [NFLX 154 65]  ===> [COMP 60 98]  ===> [MSFT 100 97]  ===> [BRK.A 23 76]  ===> [GOOGL 233 8]  ===> [TSLA 175 100]  ===> [ADBE 96 98]  ===> [INTC 54 65]  ===> [AAL 21 50]  ===> [NVDA 99 25]  ===> [AMGN 32 200]  ===> [GOOG 120 35]  ===> [QQQ 80 27]  ===> [TWTR 61.29 40]  ===> [NKE 123.5 30]  ===> [KO 53.71 25]  ===> [ORCL 91.34 37]  ===> [BABA 144.1 45]

    sl.mid_stock();//finding and printing out the middle element
    //OUTPUT : The middle stock is => [INTC 54 65] => located at the 11th position

    sl.split_list();//splitting and printing out the 2 linked lists
    //OUTPUT : The middle stock is => [INTC 54 65] => located at the 11th position
    //First list
    //List : Head ===> [FB 333 0]  ===> [TTM 22 50]  ===> [AAPL 150 500]  ===> [AMZN 189 200]  ===> [NFLX 154 65]  ===> [COMP 60 98]  ===> [MSFT 100 97]  ===> [BRK.A 23 76]  ===> [GOOGL 233 8]  ===> [TSLA 175 100]  ===> [ADBE 96 98]
    //
    //Second list
    //List : Head ===> [INTC 54 65]  ===> [AAL 21 50]  ===> [NVDA 99 25]  ===> [AMGN 32 200]  ===> [GOOG 120 35]  ===> [QQQ 80 27]  ===> [TWTR 61.29 40]  ===> [NKE 123.5 30]  ===> [KO 53.71 25]  ===> [ORCL 91.34 37]  ===> [BABA 144.1 45]
}
