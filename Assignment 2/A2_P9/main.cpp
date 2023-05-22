//problem 9 assign2
#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

void mirror(node* node);


bool structcheck(node* x, node* y);

bool isFoldable(node* root)
{
    bool res;


    if (root == NULL)
        return true;


    mirror(root->left);


    res = structcheck(root->left, root->right);

    /* Get the original tree back */
    mirror(root->left);

    return res;
}

bool structcheck(node* x, node* y)
{
    if (x == NULL && y == NULL) {
        return true;
    }
    if (x != NULL && y != NULL && structcheck(x->left, y->left) && structcheck(x->right, y->right)) {
        return true;
    }

    return false;
}


void mirror(node* Node)
{
    if (Node == NULL)
        return;
    else {
        node* temp;

        /* do the subtrees */
        mirror(Node->left);
        mirror(Node->right);

        /* swap the pointers in this node */
        temp = Node->left;
        Node->left = Node->right;
        Node->right = temp;
    }
}

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}


int main(void)
{
    cout<<"------------test case 1---------------"<<endl;
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->left->right = newNode(5);

    if (isFoldable(root) == 1) {
        cout << "tree is foldable";
    }
    else {
        cout << "tree is not foldable";
    }
    cout<<endl;
    cout<<endl;
    //------------------------

    cout<<"------------test case 2---------------"<<endl;
    node* root2 = newNode(5);
    root2->left = newNode(3);
    root2->right = newNode(7);
    root2->right->left = newNode(6);
    root2->right->right = newNode(9);

    if (isFoldable(root2) == 1) {
        cout << "tree is foldable";
    }
    else {
        cout << "tree is not foldable";
    }
    cout<<endl;
    cout<<endl;
//--------------------------

    cout<<"------------test case 3---------------"<<endl;
    node* root3 = newNode(11);
    root3->left = newNode(4);
    root3->right = newNode(17);
    root3->right->right = newNode(34);
    root3->left->right = newNode(8);
    root3->left->left = newNode(1);

    if (isFoldable(root3) == 1) {
        cout << "tree is foldable";
    }
    else {
        cout << "tree is not foldable";
    }
    cout<<endl;
    cout<<endl;
//-----------------------------
    cout<<"------------test case 4---------------"<<endl;
    node* root4 = newNode(8);
    root4->left = newNode(3);
    root4->right = newNode(10);
    root4->right->right = newNode(14);
    root4->right->right->left = newNode(13);
    root4->left->right = newNode(6);
    root4->left->left = newNode(1);

    if (isFoldable(root4) == 1) {
        cout << "tree is foldable";
    }
    else {
        cout << "tree is not foldable";
    }
    cout<<endl;
    cout<<endl;
//----------------------
    cout<<"------------test case 5---------------"<<endl;
    node* root5 = newNode(1);
    root5->left = newNode(2);
    root5->right = newNode(3);
    root5->right->left = newNode(6);
    root5->right->right = newNode(7);
    root5->left->right = newNode(5);
    root5->left->left = newNode(4);




    if (isFoldable(root5) == 1) {
        cout << "tree is foldable";
    }
    else {
        cout << "tree is not foldable";
    }
    return 0;
}
