#include <iostream>
#include <vector>
using namespace std;
template<class type>
class list{
private:
struct Node{
    type item;
    Node *next,*prev;
};
Node * head , *tail;
int length;
public:
    class iterator{
    public:
        Node *curNode;
        Node * dummyNode ;
    public:
        iterator(){
            curNode=NULL;
            dummyNode=NULL;
        }
        iterator(Node *newNode,Node *h){
            curNode=newNode;
            dummyNode=h;
        }
        void operator++() {

            if (curNode->next == NULL) {
                throw ("out of the range") ;
            } else
                curNode = curNode->next;

        }
        void operator--(){
            if (curNode->prev==NULL){
                throw ;
            }
            else {
                curNode=curNode->prev;
            }
        }
        type operator*(){
            return curNode->item;
        }
        bool operator ==(const iterator &it){
            return curNode==it.curNode;
        }
        bool operator !=(const iterator &it){
            return curNode==it.curNode;
        }
    };
    list<type>() {
        head=tail=NULL;
        length=0;
    }
    list(type value,int size){
        Node * temp = new Node;
        temp->item=value;
        temp->next=temp->prev=NULL;
        head=tail=temp;
        for (int i = 0; i <size-1 ; ++i) {
            Node *newNode = new Node;
            newNode->item=value;
            newNode->next=NULL;
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
            //cout<<"done"<<endl;
        }
        length=size;
    }
    iterator begin(){
        return iterator(head,head);
    }
    iterator end(){
        return iterator(tail,head);
    }
    void Push_back(type element){
        Node * newNode = new Node;
        newNode->item=element;
        newNode->next=NULL;
        if(head==NULL){
            head=tail=newNode;
        }
        else {
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }

        length++;
    }
    int size(){
        return length;
    }
    list<type>& operator = (list<type> &another_list){
        if( this == &another_list )
            return *this;
        iterator itr =another_list.begin();
        this->Push_back(*itr);
        while (itr!=another_list.end()){
            ++itr;
            this->Push_back(*itr);
        }
        return *this;
    }
    iterator erase(iterator &position) {
        if (position.curNode == tail) {
            --position;
            pop_back();
            return position;
        } else {
            Node *cur = position.curNode->next;
            Node *deleteNode = position.curNode;
            cur->prev = deleteNode->prev;
            position.curNode->prev->next = cur;
            ++position;
            delete deleteNode;
            length--;
            return position;
        }
    }
    void pop_back(){
        if( length ==0) {
            cout<<"The list is empty"<<endl;
            return;
        }
        else if (length==1){
            delete head;
            head=tail=NULL;
        }
        else {
           Node *cur = tail;
           tail=tail->prev;
           tail->next=NULL;
            delete cur;
        }
        length--;
    }
    void Push_Front(type element){
        Node * newNode = new Node;
        newNode->item=element;
        if(length==0){
            head=tail=newNode;
            newNode->next=newNode->prev=NULL;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        length++;
    }
    void insert(type value, int position){
        if (position<0||position>length){
            throw ("out of the range");
        }
        else{
            if(position==0)Push_Front(value);
            else if(position==length)Push_back(value);
            else {
                Node *newNode = new Node;
                newNode->item=value;
                Node *cur=head;
                for (int i = 1; i < position; ++i) {
                    cur=cur->next;
                }
                newNode->next=cur->next;
                newNode->prev=cur;
                cur->next->prev=newNode;
                cur->next=newNode;
                length++;
            }
        }
    }

    void display()
    {
        Node *cur=new Node;
        cur=head;
        while(cur!=NULL)
        {
            cout<<cur->item<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }



};


int main(){
    list<int>l;
    l.Push_back(1);
    cout<<l.size()<<endl;// 1
    l.Push_back(2);
    l.Push_back(3);
    l.Push_back(4);
    l.Push_back(5);
    l.Push_back(6);
    cout<<l.size()<<endl; // 6
    l.pop_back();
    l.pop_back();
    cout<<l.size()<<endl; // 4
    list<int>::iterator it =l.begin();
    cout<<*it<<endl;// 1
    ++it;
    cout<<*it<<endl;// 2
    ++it;
    cout<<*it<<endl;// 3
    ++it;
    cout<<*it<<endl;// 4
    try {
        ++it;// out of the range
        cout<<*it<<endl; // not call
    }
    catch (const char * s){
        cout<<s<<endl; // out of the range
    }
    cout<<*it<<endl;//2
    l.display();
    list<int>::iterator it2 = l.erase(it);
    cout<<*it2<<endl;// 3
    cout<<"After erase"<<endl;
    l.display();
    list<int>l2=l;
    l2.display();



    return 0;
}
