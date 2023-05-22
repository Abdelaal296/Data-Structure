#include <iostream>
using namespace std;
#define end cout<<endl;
template<typename t>
class BSTNode{
public:
    t item;
    BSTNode * right,*left;

    /**********************************/
    BSTNode(){
        right=left=NULL;
        item=0;
    }

    BSTNode(t item,BSTNode * right , BSTNode*  left){
        this->item=item;
        this->right=right;
        this->left=left;
    }

};
template<typename t>
class BSTFCI{
public:
    BSTNode<t> *root;

    /**********************************************************/
    BSTFCI(){
        root = NULL;
    }
    BSTFCI(t item){
        root->item=item;
        root->left=NULL;
        root->right=NULL;
    }
    BSTNode<t>* add_node(t item, BSTNode<t>* rootnode){
        if(rootnode==NULL){
            rootnode = new BSTNode<t>;

            rootnode->item=item;

            rootnode->left=rootnode->right=NULL;
        }

        else if(item < rootnode->item){
            rootnode->left= add_node(item,rootnode->left);
        }
        else if(item > rootnode->item){
            rootnode->right= add_node(item,rootnode->right);
        }
        return rootnode;

    }
    void insert(t item){
        root = add_node(item,root);
    }
    void inOrder(BSTNode<t> * rootNode){
        if(rootNode!=NULL){

            inOrder(rootNode->left);
            cout<<rootNode->item<<" ";
            inOrder(rootNode->right);
        }

    }
    void preOrder(BSTNode<t> * rootNode){
        if(rootNode!=NULL){

            cout<<rootNode->item<<" ";
            preOrder(rootNode->left);
            preOrder(rootNode->right);
        }
    }
    void postOrder(BSTNode<t> * rootNode){
        if(rootNode!=NULL){
            postOrder(rootNode->left);
            postOrder(rootNode->right);
            cout<<rootNode->item<<" ";
        }
    }
    void printInorder(){
        inOrder(root);
        end
    }
    void printPreorder(){
        preOrder(root);
        end
    }
    void printPostorder(){
        postOrder(root);
        end
    }
    bool isBalance(int x,int y){
        return abs(x-y)<=1;
    }
    bool isBalance(BSTNode<t> * rootNode){
        int leftHeight ,rightHeight;
        if(rootNode==NULL){
            return true;
        }

        leftHeight= height(rootNode->left);
        rightHeight = height(rootNode->right);


        if(isBalance(leftHeight, rightHeight)&& isBalance(rootNode->left)&& isBalance(rootNode->right));
        else
            return false;
    }
    bool isBalance(){
        return isBalance(root);
    }



    void printRange(BSTNode<t>*rootNode,int i,int j){
        if(rootNode==NULL) return;
        if(i<rootNode->item){
            printRange(rootNode->left,i,j);
        }
        if( i<=rootNode->item && j>=rootNode->item){
            cout<<rootNode->item<<" ";
        }
        if(j>rootNode->item){
            printRange(rootNode->right,i,j);
        }
    }
    void printRange(int i,int j){
        printRange(root,i,j);
        end
    }


};
template <typename t>
int height (BSTNode<t>* node){
    if(node!=NULL){
        return max(height(node->left), height(node->right))+1;
    }
    else return 0;
}

/**************************************************/
template<typename t>
bool areIdentical(BSTNode<t> * rootNode1,BSTNode<t> * rootNode2){
    if(rootNode1==NULL&&rootNode2==NULL){
        return true;
    }
    if(rootNode1==NULL||rootNode2==NULL){
        return false;
    }
    return rootNode1->item==rootNode2->item&& areIdentical(rootNode1->left,rootNode2->left)&&
           areIdentical(rootNode1->right,rootNode2->right);

}
template<typename t>
bool isSubTree(BSTNode<t>* bigTree, BSTNode<t> * subTree){
    if(subTree==NULL){
        return true;
    }
    if(bigTree==NULL){
        return false;
    }
    if(areIdentical(bigTree,subTree)){
        return true;
    }

    return isSubTree(bigTree->left,subTree)||
    isSubTree(bigTree->right,subTree);

}
template<typename tt>
bool isSubTree(BSTFCI<tt>* t1, BSTFCI<tt>* t2){
    return isSubTree(t1->root,t2->root);
}

int main() {
    BSTFCI <int> * a1 = new BSTFCI <int>();
    BSTFCI <int> * a2 = new BSTFCI <int>();
    BSTFCI <int> * a3 = new BSTFCI <int>();
    BSTFCI <int> * a4 = new BSTFCI <int>();
    BSTFCI <int> * a5 = new BSTFCI <int>();
    BSTFCI <int> * a6 = new BSTFCI <int>();
    BSTFCI <int> * a7 = new BSTFCI <int>();

   /******************************************/
    a1->insert(15);
    a1->insert(10);
    a1->insert(6);
    a1->insert(3);
    a1->insert(8);
    a1->insert(12);
    a1->insert(11);
    a1->insert(14);
    a1->insert(20);
    a1->insert(17);
    a1->insert(16);
    a1->insert(18);
    a1->insert(22);
    a1->insert(21);
    a1->insert(23);
    if(a1->isBalance()){ // true
        cout<<"Balanced"<<endl;
    }
    else {
        cout<<"Not Balanced"<<endl;
    }
    a2->insert(16);
    a2->insert(18);
    a2->insert(22);
    a2->insert(21);
    a2->insert(23);
    if(a2->isBalance()){ // false
        cout<<"Balanced"<<endl;
    }
    else {
        cout<<"Not Balanced"<<endl;
    }



    a3->insert(5);
    a3->insert(4);
    a3->insert(3);
    a3->insert(2);
    a3->insert(1);
    if(a3->isBalance()){ // false
        cout<<"Balanced"<<endl;
    }
    else {
        cout<<"Not Balanced"<<endl;
    }

    a4->insert(5);
    a4->insert(7);
    a4->insert(3);
    a4->insert(4);
    a4->insert(2);
    a4->insert(8);
    a4->insert(6);
    if(a4->isBalance()){ // true
        cout<<"Balanced"<<endl;
    }
    else {
        cout<<"Not Balanced"<<endl;
    }
    a5->insert(5);
    a5->insert(7);
    a5->insert(3);
    a5->insert(4);
    a5->insert(2);
    a5->insert(1);

    if(a5->isBalance()){ // false
        cout<<"Balanced"<<endl;
    }
    else {
        cout<<"Not Balanced"<<endl;
    }
    a1->printInorder();// 3 6 8 10 11 12 14 15 16 17 18 20 21 22 23
    a2->printPostorder(); // 21 23 22 18 16
    a3->printPreorder();// 21 23 22 18 16
    a4->printInorder();// 2 3 4 5 6 7 8
    a5->printPostorder();// 1 2 4 3 7 5

/*******************************************************/
    a6->insert(6);
    a6->insert(3);
    a6->insert(8);

    if(isSubTree(a1,a6)){ // true
        cout<<"this is sub tree"<<endl;
    }
    else {
        cout<<"There is no sub-tree"<<endl;
    }


    if(isSubTree(a1,a2)){ // false
        cout<<"this is sub tree"<<endl;
    }
    else {
        cout<<"There is no sub-tree"<<endl;
    }

    if(isSubTree(a3,a4)){ // false
        cout<<"this is sub tree"<<endl;
    }
    else {
        cout<<"There is no sub-tree"<<endl;
    }

    if(isSubTree(a1,a7)){ // true
        cout<<"this is sub tree"<<endl;
    }
    else {
        cout<<"There is no sub-tree"<<endl;
    }

    if(isSubTree(a7,a1)){ // false
        cout<<"this is sub tree"<<endl;
    }
    else {
        cout<<"There is no sub-tree"<<endl;
    }
/******************************************************************/
 a1->printRange(1,12); // 3 6 8 10 12
 a2->printRange(1,5); // empty space
 a3->printRange(0,15);// 1 2 3 4 5
 a4->printRange(3,6);// 3 4 5 6
 a5->printRange(7,10);// 7

    return 0;
}
