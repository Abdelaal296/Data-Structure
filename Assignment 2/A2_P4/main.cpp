#include <iostream>
using namespace std ;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true ;
        }
        else
            return check(root->left , root->right);


    }
    bool check(TreeNode *left , TreeNode * right){
        if( left == nullptr && right == nullptr){
            return true ;
        }
        if (left->val == right->val){
            return check(left->left , right->right) && check(left->right ,right->left);
        } else
            return  false ;
    }
};
int main() {
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode();
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode();
    root1->right->right = new TreeNode(3);

    if (obj.isSymmetric(root))// true
        cout << "true";
    else
        cout << "false";
    cout<<endl ;
    if (obj.isSymmetric(root1))// false
        cout << "true";
    else
        cout << "false";

    return 0;
}
