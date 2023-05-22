#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


struct Node {
    char data ;
    int val;
    Node *left;
    Node *right;



};

Node* ExpressionTree(string exp){
    stack<Node*> s ;
    Node*result ;
    for(int i= exp.length()-1 ; i>=0 ; i--){
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            Node*item = new Node ;
            item ->data =exp[i] ;
            item->left = s.top();
            s.pop();
            item->right =s.top();
            s.pop();
            result=item ;
            s.push(result);

        }
        else
        {
            Node*item = new Node ;
            item->val =exp[i]-'0';
            item->left = nullptr ;
            item->right = nullptr ;
            s.push(item);
        }
    }
    result=s.top();
    s.pop();
    return result ;



}
int calculate(char pro, int a, int b)
{
    if(pro =='+')
        return (a+b);

    else if(pro =='-')
        return a-b;

    else if(pro =='*')
        return a*b;

    else
        return a/b;


}

int Evaluate(Node * q){

    if(q->data=='+'||q->data=='-'||q->data=='*'||q->data=='/'){

        return calculate(q->data,Evaluate(q->left),Evaluate(q->right));
    }
    else{

        return q->val;

    }

}
int main() {
    Node*root =ExpressionTree("+3*4/82");
    Node*root1 =ExpressionTree("+*23*89");
    Node*root2 =ExpressionTree("-+*23*549");
    Node*root3 =ExpressionTree("*+69-31");
    Node*root4 =ExpressionTree("+2*6/93");
    cout<<Evaluate(root)<<endl ;
    cout<<Evaluate(root1)<<endl ;
    cout<<Evaluate(root2)<<endl ;
    cout<<Evaluate(root3)<<endl ;
    cout<<Evaluate(root4)<<endl ;

    return 0;
}
