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
void travel(TreeNode *r,vector<int> &a)
    {
        if(r)
        {
            if(r->left){travel(r->left,a);}
            a.push_back(r->val);
            if(r->right){travel(r->right,a);}
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        travel(root,a);
        return a[k-1];
    }
};
