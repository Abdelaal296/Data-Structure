//problem 7 assig2

#include<iostream>
using namespace std;


struct Node{

    int info;
    struct Node* rlink;
    struct Node* llink;
    // constructor
    Node(int i=0, Node* rl=0, Node* ll=0){
        info=i;
        rlink=rl;
        llink=ll;}

    //getters for attributes
    int getinfo(){return info;}
    Node* getrlink(){return rlink;}
    Node* getllink(){return llink;}
};

//traversal function inorder technique
void printInorder(Node* node)
{
    if (node == NULL)
        return;


    printInorder(node->llink);
    cout << node->info << " ";
    printInorder(node->rlink);
}


//function that flip the binary tree

void flip(Node* node)
{
    //node doesn't exist
    if (node == NULL)
        return;

    else
    {
        Node* temp;

        flip(node->llink);
        flip(node->rlink);
        //swapping two nodes using temp.
        temp = node->llink;
        node->llink = node->rlink;
        node->rlink = temp;
    }
}



int main()
{
    struct Node* root = new Node(1);
    root->llink = new Node(2);
    root->rlink = new Node(3);
    root->llink->llink = new Node(4);
    root->llink->rlink = new Node(5);


    cout << "the inorder traversal of binary tree 1 before fliping is : "<<endl;
    printInorder(root);
    cout<<endl;
    cout << "the inorder traversal of binary tree 1 after fliping is : "<<endl;
    flip(root);
    printInorder(root);
    cout<<endl;

    cout<<"---------------------------"<<endl;
    //-------------------------------

    struct Node* root2 = new Node(5);
    root2->llink = new Node(4);
    root2->rlink = new Node(9);
    root2->llink->llink = new Node(3);
    root2->llink->rlink = new Node(6);
    root2->rlink->rlink = new Node(10);
    root2->rlink->llink = new Node(8);



    cout << "the inorder traversal of binary tree 2 before fliping is : "<<endl;
    printInorder(root2);
    cout<<endl;
    cout << "the inorder traversal of binary tree 2 after fliping is : "<<endl;
    flip(root2);
    printInorder(root2);

    cout<<endl;
    cout<<"-----------------------------"<<endl;

//--------------------------------


    struct Node* root3 = new Node(5);
    root3->llink = new Node(4);
    root3->rlink = new Node(9);
    root3->rlink->rlink = new Node(10);
    root3->rlink->llink = new Node(8);
    root3->llink->llink = new Node(3);
    root3->llink->rlink = new Node(6);

    root3->llink->llink->llink=new Node(1);
    root3->llink->llink->rlink=new Node(2);




    cout << "the inorder traversal of binary tree 3 before fliping is : "<<endl;
    printInorder(root3);
    cout<<endl;
    cout << "the inorder traversal of binary tree 3 after fliping is : "<<endl;
    flip(root3);
    printInorder(root3);

    cout<<endl;
    cout<<"--------------------------"<<endl;


//--------------------------------


    struct Node* root4 = new Node(5);
    root4->llink = new Node(4);
    root4->rlink = new Node(9);



    cout << "the inorder traversal of binary tree 4 before fliping is : "<<endl;
    printInorder(root4);
    cout<<endl;
    cout << "the inorder traversal of binary tree 4 after fliping is : "<<endl;
    flip(root4);
    printInorder(root4);

    cout<<endl;
    cout<<"--------------------------"<<endl;

//------------------------------------


    struct Node* root5 = new Node(5);




    cout << "the inorder traversal of binary tree 5 before fliping is : "<<endl;
    printInorder(root5);
    cout<<endl;
    cout << "the inorder traversal of binary tree 5 after fliping is : "<<endl;
    flip(root5);
    printInorder(root5);

    cout<<endl;
    cout<<"--------------------------"<<endl;

//------------------------------------



    return 0;
}


/*
//function to swap two nodes using temp
void swapp(Node* obj1,Node* obj2){
    Node* temp=new Node();
    temp=obj1;
    temp->llink=obj1->llink;
    temp->rlink=obj1->rlink;

    obj1=obj2;
    obj1->llink=obj2->llink;
    obj1->rlink=obj2->rlink;

    obj2=temp;
    obj2->llink=temp->llink;
    obj2->rlink=temp->rlink;

}

//function that flip the binary tree as in the mirror
void flip(Node* node){

    Node* first=new Node();
    Node* sec=new Node();
    first=sec=node;

    if(node->llink!=NULL && node->rlink==NULL){
        node->rlink=node->llink;
    node->llink=NULL;
    return;}
    else if(node->llink==NULL && node->rlink!=NULL)
    {
         node->llink=node->rlink;
    node->rlink=NULL;
    return;}


if(node->llink!=NULL && node->rlink!=NULL){
    first=first->llink;
    sec=sec->rlink;
    swapp(first,sec);


node->llink=sec;
node->rlink=first;}



if(first->llink!=NULL || first->rlink!=NULL){
    flip(first);}




if(sec->llink !=NULL || sec->rlink!=NULL){
flip(sec);}




else
    return;
}
*/
