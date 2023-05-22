//problem 10 assignment2
#include <iostream>
#include<vector>
using namespace std;


class BST {
    int data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST* Insert(BST*, int);

    // Inorder traversal.
    void Inorder(BST*,vector<int>&);

    //function to calculate total sum
    int result(BST*,int,vector<int>&);
};

// Default Constructor definition.
BST ::BST()
{
    data=0;
    left=right=NULL;
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function definition that store every element found in the tree in a vector in order way.

void BST ::Inorder(BST* root,vector<int>&vec)
{


    if(root==NULL)
        return;


    Inorder(root->left,vec);

    vec.push_back(root->data);


    Inorder(root->right,vec);
}

//result function definition that added every value less than or equal of kth smallest one in the tree
int BST ::result(BST* root,int k,vector<int>& vec)
{

    int sum=0;
    Inorder(root,vec);
    if(k>vec.size())
    {
        cout<<"k is greater than number of nodes in the tree";
        return 0;
    }
    for(int i=0; i<k; i++)
    {
        sum+=vec[i];
    }



    return sum;

}




int main()
{
    vector<int> v;
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
    int k;

    cout<<" ------------test case number 1 ------------"<<endl;
    cout<<"please enter k : ";
    cin>>k;
    cout<<endl;
    cout<<"the total sum is : "<<b.result(root,k,v)<<endl;

//-------------------------------------------

    vector<int>v2;
    BST b2, *root2 = NULL;
    root2 = b2.Insert(root2, 54);
    b2.Insert(root2, 51);
    b2.Insert(root2, 49);
    b2.Insert(root2, 52);
    b2.Insert(root2, 75);
    b2.Insert(root2, 85);
    b2.Insert(root2, 74);

    int k2;
    cout<<" ------------test case number 2 ------------"<<endl;
    cout<<"please enter k : ";
    cin>>k2;
    cout<<endl;
    cout<<"the total sum is : "<<b2.result(root2,k2,v2)<<endl;
//-------------------------------------------

    vector<int>v3;
    BST b3, *root3 = NULL;
    root3 = b3.Insert(root3, 70);
    b3.Insert(root3, 32);
    b3.Insert(root3, 15);
    b3.Insert(root3, 40);
    b3.Insert(root3, 75);

    int k3;
    cout<<" ------------test case number 3 ------------"<<endl;
    cout<<"please enter k : ";
    cin>>k3;
    cout<<endl;
    cout<<"the total sum is : "<<b3.result(root3,k3,v3)<<endl;
//-------------------------------------------

    vector<int>v4;
    BST b4, *root4 = NULL;
    root4 = b4.Insert(root4, 111);
    b4.Insert(root4, 99);
    b4.Insert(root4, 88);
    b4.Insert(root4, 77);
    b4.Insert(root4, 22);
    b4.Insert(root4, 44);
    b4.Insert(root4, 55);
    b4.Insert(root4, 66);

    int k4;
    cout<<" ------------test case number 4 ------------"<<endl;
    cout<<"please enter k : ";
    cin>>k4;
    cout<<endl;
    cout<<"the total sum is : "<<b4.result(root4,k4,v4)<<endl;
//-------------------------------------------

    vector<int>v5;
    BST b5, *root5 = NULL;
    root5 = b5.Insert(root5, 7);
    b5.Insert(root5, 9);
    b5.Insert(root5, 8);
    b5.Insert(root5, 3);

    int k5;
    cout<<" ------------test case number 5 ------------"<<endl;
    cout<<"please enter k : ";
    cin>>k5;
    cout<<endl;
    cout<<"the total sum is : "<<b5.result(root5,k5,v5)<<endl;
//-------------------------------------------



    return 0;
}


