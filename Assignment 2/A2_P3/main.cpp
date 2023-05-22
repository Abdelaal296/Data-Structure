#include <iostream>
using namespace std;
const int SIZE=100;
class queue{
    int front;
    int rear;
    int *arr;
    int cap;
    int length;
public:
    queue(int size=SIZE){
        cap=size;
        arr=new int[size];
        front=-1;
        rear=-1;
        length=0;
    }

    bool isEmpty(){
        return (front==-1&&rear==-1);
    }
    bool isFull(){
        if(front==0&& rear== cap-1) return true;

        else if (rear==front-1) return true;
        else return false;
    }
    void enqueue(int val){

        if(isFull())return;

        if(isEmpty()){
            front=0;
            rear=0;
            arr[rear]=val;
        }
        else if(rear==cap-1){
            rear=0;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
        ++length;

    }
    void dequeue(){
        if(isEmpty()) return;

        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==cap-1){
            front=0;
        }
        else{
            front++;

        }
        --length;
    }

    int getFront(){
        if(isEmpty()) return 0;
        else{
            return arr[front];
        }
    }
    int getSize(){
        return length;
    }
};



class stack{
    queue q;
public:
    void push(int val){
        if(q.isFull()) {
            cout<<"stack is Full"<<endl;
            return;
        }
        else{
            int s=q.getSize();
            q.enqueue(val);
            for (int i = 0; i < s; ++i) {
                q.enqueue(q.getFront());
                q.dequeue();
            }
        }


    }

    void pop(){
        if(q.isEmpty()){
            cout<<"stack is Empty"<<endl;
            return;
        }
        q.dequeue();
    }
    int Top(){
        if(q.isEmpty()) {
            cout<<"stack is Empty"<<endl;
            return 0;
        }
        else {
            return q.getFront();
        }
    }
};
int main() {


    stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;


}
