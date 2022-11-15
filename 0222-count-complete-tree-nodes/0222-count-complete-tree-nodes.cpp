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
    int getLh(TreeNode* root){
        if(!root)return 0;
        
        return 1 + getLh(root->left);
    }
    int getRh(TreeNode* root){
        if(!root)return 0;
        
        return 1 + getRh(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh = getLh(root);
        int rh = getRh(root);
        if(lh == rh)return (1<<lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};