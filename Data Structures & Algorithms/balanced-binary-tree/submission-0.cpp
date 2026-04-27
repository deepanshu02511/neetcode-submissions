/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxh(TreeNode* root)
    {
        if(!root){return 0;}
        int l=maxh(root->left),r=maxh(root->right);
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        int a=maxh(root->left),b=maxh(root->right);
        if(abs(a-b)>1){return false;}
        else if(root->left || root->right)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return true;
    }
};
