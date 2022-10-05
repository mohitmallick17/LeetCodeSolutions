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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return NULL;
        
        if(depth-1==0){
            auto node = new TreeNode(val);
            node->left = root;
            
            return node;
        }
        
        if(depth-1==1){
            TreeNode* new_left = new TreeNode(val);
            new_left->left = root->left;
            root->left = new_left;
            
            
            TreeNode* new_right = new TreeNode(val);
            new_right->right = root->right;
            root->right =new_right;
            
            return root;
        }
        
        root->left = addOneRow(root->left, val, depth-1);
        root->right = addOneRow(root->right, val, depth-1);
        
        return root;
    }
};