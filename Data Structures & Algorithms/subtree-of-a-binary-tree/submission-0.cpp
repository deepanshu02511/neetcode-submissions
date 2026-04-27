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
    bool t(TreeNode* p, TreeNode* q)
    {
        if(!p && !q){return true;}
        if((!p && q) || (!q && p)){return false;}
        if(p->val!=q->val){return false;}
        
        else return (t(p->left,q->left) && t(q->right,p->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return t(p,q);
    }
    void printInorder(TreeNode* node,TreeNode *sub,bool &a)
    {
        if (node == NULL || sub==NULL){ return;}
        if (isSameTree(node,sub))
            a=1;
        

        /* first recur on left child */
        printInorder(node->left,sub,a);


        /* now recur on right child */
        printInorder(node->right,sub,a);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool a=0;
        printInorder(root,subRoot,a);
        if(a){return true;}
        return false;
    }
};
