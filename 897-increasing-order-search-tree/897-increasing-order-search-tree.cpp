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
    TreeNode* rt = NULL, *cur=NULL;
    void solve(TreeNode* root){
        if(!root)return;
        solve(root->left);
        if(rt==NULL){
            rt=cur=root;
        }else{
            cur->right=root;
            cur=cur->right;
        }
        if(cur->left)cur->left=NULL;
        solve(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        return rt;
    }
};