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
    int dfs(TreeNode *root,int &ans)
    {
        if(!root){return 0;}
        int l=dfs(root->left,ans);
        int r=dfs(root->right,ans);
        int m=max(l,r);
        ans=max(ans,l+r+root->val);
        ans=max(ans,l+root->val);
        ans=max(ans,r+root->val);
        ans=max(ans,root->val);
        return max(root->val,m+root->val);

    }
    int maxPathSum(TreeNode* root) {
        int ans=-1001;
        int a=dfs(root,ans);
        return ans;
    }
};
