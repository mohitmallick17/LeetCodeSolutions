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
    bool solve(TreeNode* root){
        if(!root)return false;
        
        bool l = solve(root->left);
        bool r = solve(root->right);
        
        if(l==false)root->left=NULL;
        if(r==false)root->right=NULL;
        
        bool ans = (l || r || root->val==1);
        
        return ans;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(solve(root)==false)return NULL;
        return root;
    }
};