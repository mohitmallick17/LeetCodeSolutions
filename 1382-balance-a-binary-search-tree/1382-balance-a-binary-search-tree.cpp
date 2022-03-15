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
    void inorder(TreeNode* root, vector<TreeNode*> &v){
        if(!root)return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
        if(root->left)
            root->left = NULL;
        if(root->right)
            root->right = NULL;
    }
    TreeNode* solve(int start, int end, vector<TreeNode*>& v){
        if(start > end)return NULL;
        int mid = start + (end-start)/2;
        TreeNode* root = v[mid];
        root->left = solve(start, mid-1, v);
        root->right = solve(mid+1, end, v);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        
        return solve(0, v.size()-1, v);
    }
};