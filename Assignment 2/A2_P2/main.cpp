#include <iostream>
using namespace std;
const int SIZE=100;
class queue{
    int front;
    int rear;
    int *arr;
    int cap;
public:
    queue(int size=SIZE){
        cap=size;
        arr=new int[size];
        front=-1;
        rear=-1;
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

    }

    int getFront(){
        if(isEmpty()) return 0;
        else{
            return arr[front];
        }
    }


};



int calcSeconds(int* arr1,int size,int kk){

    queue q(size);
    int seconds=0;
    for (int i = 0; i < size; ++i) {

        q.enqueue(i);
    }

    while(!q.isEmpty()){

        int temp=q.getFront();


        q.dequeue();
        if(arr1[temp]>0){
            ++seconds;
            arr1[temp]--;

            q.enqueue(temp);
        }

        if(arr1[temp]==0&&temp!=kk) {

            continue;
        }
        if(arr1[temp]==0&&temp==kk)break;
    }

    return seconds;
}
int arr[SIZE];
int main() {


    int n;
    cout<<"How many people in the line ?"<< endl;
    cin>>n;

    cout<<"Enter number of tickets Respectively"<<endl;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    int k;
    cout<<"Enter position: "<<endl;
    cin>>k;
    cout<<calcSeconds(arr,n,k)<<endl;

}