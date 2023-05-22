//problem 8 assignment 2
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char item;
    Node*left,*right;

};


int search (string traversal,char x, int len)
{
    for(int i = 0;i<len;i++)
    {

        if(traversal[i]==x)
        {
            return i;
        }


    }
}

Node *newnode(char item)
{
    Node *nnode = new Node();
    nnode->item = item;
    nnode->left = 0;
    nnode->right = 0;
    return (nnode);
}
Node* buildtree(string& preod,string& inod, int instrt, int inend )
{
    int length=inod.size();
    static int preindex = 0;
    if (instrt>inend)
        return 0;
    Node *tnode = newnode(preod[preindex++]);
    if(instrt == inend)
        return tnode;
    int inindex = search(inod,tnode->item,length);
    tnode->left = buildtree(preod, inod, instrt, inindex - 1);
    tnode->right = buildtree(preod, inod, inindex + 1, inend);

    return tnode;

}





void postorder(Node *p)
{
    if(p==NULL)
        return;

    postorder(p->left);
    postorder(p->right);
    cout<<p->item;


}
void printpostod(string& preod,string& inod)
{
    int length = preod.size();
    Node* root = buildtree(preod, inod, 0, length - 1);
    postorder(root);


}


int main()
{

    cout<<"enter the number of case you want to run FROM 1 TO 5 "<<endl;
    int ch;
    cin>>ch;
    cout<<endl;

    if(ch==1){
        string preorderi="ABFGC",inorderi="FBGAC";
        cout<<"--------------Test Case 1--------------"<<endl;
        printpostod(preorderi,inorderi);
        cout<<endl;}

    else if(ch==2){

        string preodii="ABCDEFGHI",inodii="CBEDAHGFI";

        cout<<"---------------Test Case 2--------------"<<endl;
        printpostod(preodii,inodii);}


    else if(ch==3){
        string preodii="EXAMFUN",inodii="MAFXUEN";

        cout<<"---------------Test Case 3--------------"<<endl;
        printpostod(preodii,inodii);}



    else if(ch==4){
        string preodii="HBDIACEFG",inodii="DAICBHEGF";

        cout<<"---------------Test Case 4--------------"<<endl;
        printpostod(preodii,inodii);}

    else
    {
        string preodii="ABC",inodii="BAC";

        cout<<"---------------Test Case 5--------------"<<endl;
        printpostod(preodii,inodii);
    }





    /*
    Test case 1:
    (ABFGC,FBGAC)
     Answer: FGBCA

     Test case 2:
    (ABCDEFGHI,CBEDAHGFI)
    Answer: CEDBHGIFA


    Test case 3:
    (EXAMFUN,MAFXUEN)
    Answer: MFAUXNE

    Test case 4:
    (HBDIACEFG,DAICBHEGF)
    Answer: ACIDBGFEH


    Test case 5:
    (ABC,BAC)
    Answer: BCA
    */




    return 0;
}
