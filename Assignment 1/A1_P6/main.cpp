#include <bits/stdc++.h>
#include "PhoneDirectory.h"
using namespace std;
void menu();
int main()
{
    PhoneDirectory *p;
    p=new PhoneDirectory;
    int choice1,num;
    string fName,lName,phone,searchphone,searchName;
    bool flag= false;
    while (true){
        menu();
        cin>>choice1;
        switch (choice1) {
            case 1:
                cout<<"Enter first name :";
                cin>>fName;
                cout<<"Enter last name :";
                cin>>lName;
                cout<<"Enter phone number :";
                cin>>phone;
                p->insertFront(fName,lName,phone);
                break;
            case 2:
                cout<<"Enter phone number : ";
                cin>>searchphone;
                p->searchByPhoneNumber(searchphone);
                break;
            case 3:
                cout<<"Enter First name : ";
                cin>>searchName;
                p->searchByFirstName(searchName);
                break;
            case 4:
                cout<<"Enter First name : ";
                cin>>searchName;
                p->DeleteByFirstName(searchName);
                break;
            case 5:
                num= (rand() % 3) + 1;
                if(num==1){
                    p->insertionsort();
                }
                else if(num==2){
                    p->bubbleSort();
                }
                else if(num==3){
                    p->selectionSort();
                }
                p->print();
                break;
            case 6:
                flag= true;
                break;
        }
        if(flag)break;
    }


    return 0;
}
void menu(){
    cout<<"1. Add an entry to the directory"<<endl
        <<"2. Look up a phone number"<<endl
        <<"3. Look up by first name"<<endl
        <<"4. Delete an entry from the directory by first name"<<endl
        <<"5. List All entries in phone directory"<<endl
        <<"6. Exit form this program"<<endl;
}