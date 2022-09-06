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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return NULL;
        
        TreeNode* l = pruneTree(root->left);
        TreeNode* r = pruneTree(root->right);
        
        if(l==NULL)root->left=NULL;
        if(r==NULL)root->right=NULL;
        
        if(l || r || root->val==1)return root;
        
        return NULL;
    }
};