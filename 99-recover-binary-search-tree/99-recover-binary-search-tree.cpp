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
    TreeNode* prev=NULL;
    TreeNode *first=NULL, *mid=NULL, *last=NULL;
    
    void solve(TreeNode* root){
        if(!root)return;
        
        solve(root->left);
        
        if(prev and root->val < prev->val){
            if(!first){
                first=prev;
                mid=root;
            }else
                last=root;
        }
        prev=root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
        if(last)swap(first->val, last->val);
        else if(first)swap(first->val, mid->val);
    }
};