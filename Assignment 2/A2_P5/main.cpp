#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL||q==NULL){
            return false;
        }
        return p->val==q->val&& isSameTree(p->left,q->left)&&
               isSameTree(p->right,q->right);
    }
};




int main() {
/* Example 1
    1        1
  2   3    2    3


*/
    Solution obj1;
    TreeNode *head1 = new TreeNode(1);
    TreeNode *head2 = new TreeNode(1);
    head1->left=new TreeNode(2);
    head1->right= new TreeNode(3);
    head2->left=new TreeNode(2);
    head2->right= new TreeNode(3);
    if(obj1.isSameTree(head1,head2))// true
    {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }
/*********************************************/
/* Example 2
    1        1
  2             2


*/

    TreeNode *head3 = new TreeNode(1);
    TreeNode *head4 = new TreeNode(1);
    head3->left=new TreeNode(2);
    head4->right= new TreeNode(2);
    if(obj1.isSameTree(head3,head4))// false
    {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }
    /*******************************************/
    /* Example 3

    1        1
  2   1    1   2

     */


    TreeNode *head5 = new TreeNode(1);
    TreeNode *head6 = new TreeNode(1);
    head5->left=new TreeNode(2);
    head5->right= new TreeNode(1);
    head6->left=new TreeNode(1);
    head6->right= new TreeNode(3);
    if(obj1.isSameTree(head5,head6))// false
    {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }




    return 0;
}
