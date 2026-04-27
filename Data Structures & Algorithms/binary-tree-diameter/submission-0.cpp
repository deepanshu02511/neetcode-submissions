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
        int l=maxh(root->left);
        int r=maxh(root->right);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){return 0;}
        int t=maxh(root->left)+maxh(root->right);
        int l=diameterOfBinaryTree(root->left);
        int r=diameterOfBinaryTree(root->right);
        // cout<<"t "<<t<<" l "<<l<<" r "<<r<<endl;
        return max(t,max(l,r));
    }
};
