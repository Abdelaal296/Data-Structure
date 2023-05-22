#include <iostream>
using namespace std;

const int MAX=1000;

template <class t>
class stack {
    int top;
    t s[MAX];
public:
    stack(){
        top=-1;
    }
    stack(t x){
        if(top==MAX-1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top =-1;
            s[++top]=x;
        }
    }

    void push(t x){
        if(top==MAX-1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            ++top;
            s[top]=x;
        }

    }
    void pop(){
        if(top<0){
            cout<<"stack is empty "<<endl;
            return;
        }
        else{

            top--;
        }

    }
    t Top(){
        if(top<0){
            cout<<"stack is empty "<<endl;
            return 0;
        }
        else {
            return s[top];
        }

    }
    void print(){
        if(top<0){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<endl;
            for (int i = 0; i <= top; ++i) {
                cout<<s[i]<<" ";

            }
            cout<<endl;
        }
    }
    bool isEmpty(){
        return (top<0);
    }

};

string simplify(string input){
    stack<string>st1;
    string temp;
    string res="/";
    for (int i = 0; i < input.length(); ++i) {
        temp="";

        while(input[i]=='/')
            i++;

        while (input[i]!='/'&&i<input.length()) {
            temp+=input[i];
            i++;
        }
        if(temp=="..")
        {
            if(!st1.isEmpty())
                st1.pop();
        }
        else if(temp==".")
            continue;
        else {
            if(temp.length()!=0) {
                st1.push(temp);
            }
        }



    }
    stack<string>st2;
    while(!st1.isEmpty()){
        st2.push(st1.Top());
        st1.pop();
    }

    while(!st2.isEmpty()){
        res+=st2.Top();
        st2.pop();
        if(!st2.isEmpty())
            res+='/';
    }


    return res;
}

int main() {

    string path;
    cin>>path;
    cout<<simplify(path);

}

