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
    void travel(TreeNode *r,int &ans,int m)
    {
        if(!r){return;}
        if(r->val>=m){ans++;m=max(m,r->val);}
        travel(r->left,ans,m);
        travel(r->right,ans,m);
    }

    int goodNodes(TreeNode* root) {
        int ans=0,m=-101;
        travel(root,ans,m);
        return ans;
    }
};
