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
    void travel(TreeNode*r,int c,vector<vector<int>> &ans)
    {
        if(!r){return;}
        if(ans.size()>c){ans[c].push_back(r->val);}
        else{
            vector<int> a;
            ans.push_back(a);
            ans[c].push_back(r->val);
        }
        
        travel(r->right,c+1,ans);
        travel(r->left,c+1,ans);
        return;

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int c=0;
        vector<vector<int>> ans;
        travel(root,0,ans);
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> a=levelOrder(root);
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            ans.push_back(a[i][0]);
        }
        return ans;
    }
};
