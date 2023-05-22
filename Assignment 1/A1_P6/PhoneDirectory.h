#include <bits/stdc++.h>
using namespace std;
class PhoneDirectory{
    struct Node{
        string firstName ;
        string lastName ;
        string PhoneNumber;
        Node * next;
    };
    Node * head,*tail,*sorted;
    int length;
public:
    PhoneDirectory(){
        head=tail=NULL;
        sorted=NULL;
        length=0;
    }
    void insertFront(string fname,string lName,string phone){
        Node * newNode = new Node;
        newNode->firstName=fname;
        newNode->lastName=lName;
        newNode->PhoneNumber=phone;
        if(length==0){
            head=tail=newNode;
            newNode->next=NULL;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        length++;
    }
    void DeleteByFirstName(string fName ){
        if( length ==0) {
            cout<<"The list is empty"<<endl;
            return;
        }
        Node *cur,*prev;
        if(head->firstName==fName){
            cur = head;
            head=head->next;
            delete cur;
            length--;
            if(length==0){
                tail=NULL;
            }
        }
        else {
            cur=head->next;
            prev=head;
            while (cur!=NULL){
                if(cur->firstName==fName)break;
                prev=prev->next;
                cur=cur->next;
            }
            if(cur==NULL)
            {
                cout<<"the element not found"<<endl;
            }
            else {
                prev->next=cur->next;
                if(tail==cur){
                    tail=prev;
                }
                delete cur ;
                length--;
            }
        }
        return;
    }
    void searchByFirstName(string name){
        Node *cur =head;
        while (cur!=NULL){
            if(cur->firstName==name){
                cout<<"First Name :"<<cur->firstName<<endl;
                cout<<"Last Name :"<<cur->lastName<<endl;
                cout<<"Phone Number :"<<cur->PhoneNumber<<endl;
                cout<<".................................................."<<endl;
                return;
            }
            cur=cur->next;
        }
        cout<<"Element does not found"<<endl;
    }
    void searchByPhoneNumber(string phone){
        Node *cur =head;
        while (cur!=NULL){
            if(cur->PhoneNumber==phone){
                cout<<"First Name :"<<cur->firstName<<endl;
                cout<<"Last Name :"<<cur->lastName<<endl;
                cout<<"Phone Number :"<<cur->PhoneNumber<<endl;
                cout<<".................................................."<<endl;
                return;
            }
            cur=cur->next;
        }
        cout<<"Element does not found"<<endl;
    }
    //  insertion sort
    void sortedInsert( Node* newnode)
    {
        if (sorted == NULL || sorted->firstName >= newnode->firstName) {
            newnode->next = sorted;
            sorted = newnode;
        }
        else {
            Node* current = sorted;
            while (current->next != NULL && current->next->firstName < newnode->firstName) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    void insertionsort()
    {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
    }
    // bubble sort
    Node* swap(Node* ptr1,Node* ptr2)
    {
        struct Node* tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }
    int bubbleSort()
    {
        Node** h;
        bool flag;

        for (int i = 0; i <  length; i++)
        {
            h = &head;
            flag = false;
            for (int j = 0; j < length - i -1; j++)
            {
                Node* p1 = *h;
                Node* p2 = p1->next;
                if (p1->firstName > p2->firstName)
                {
                    *h = swap(p1, p2);
                    flag = true;
                }
                h = &(*h)->next;
            }

            if (!flag)
                break;
        }
    }
    void print(){
        Node*cur =head;
        while (cur!=NULL){
            cout<<"First Name :"<<cur->firstName<<endl;
            cout<<"Last Name :"<<cur->lastName<<endl;
            cout<<"Phone Number :"<<cur->PhoneNumber<<endl;
            cout<<".................................................."<<endl;
            cur=cur->next;
        }
        cout<<endl;
    }
    // selection sort
    Node* selectionSort()
    {
        Node *tmp, *i,  *j, *a, *b;

        tmp = i = head;

        while (i->next!=NULL) {

            a = j = i->next;

            while (j!=NULL) {

                if (i->firstName > j->firstName) {

                    if (i->next == j) {

                        if (i == head) {

                            i->next = j->next;
                            j->next = i;

                            b = i;
                            i = j;
                            j = b;

                            a = j;

                            head = i;

                            j = j->next;
                        }
                        else {
                            i->next = j->next;
                            j->next = i;
                            tmp->next = j;

                            b = i;
                            i = j;
                            j = b;

                            a = j;
                            j = j->next;
                        }
                    }

                    else {

                        if (i == head) {
                            b = i->next;
                            i->next = j->next;
                            j->next = b;
                            a->next = i;

                            b = i;
                            i = j;
                            j = b;

                            a = j;

                            j = j->next;

                            head = i;
                        }

                        else {
                            b = i->next;
                            i->next = j->next;
                            j->next = b;
                            a->next = i;
                            tmp->next = j;

                            b = i;
                            i = j;
                            j = b;

                            a = j;
                            j = j->next;
                        }
                    }
                }
                else {
                    a = j;
                    j = j->next;
                }
            }

            tmp = i;
            i = i->next;
        }
    }


};