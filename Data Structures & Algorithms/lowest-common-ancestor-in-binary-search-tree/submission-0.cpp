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
    bool find(TreeNode *r,TreeNode*p)
    {
        if(!r){return false;}
        if(r==p){return true;}
        bool l=find(r->left,p);
        bool rr=find(r->right,p);
        if(rr || l) return true;
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool pl=find(root->left,p);
        bool pr=find(root->right,p);
        bool ql=find(root->left,q);
        bool qr=find(root->right,q);
        if(pl && ql){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(pr && qr){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if((pl && qr) || (pr && ql)){return root;}
    }
};
