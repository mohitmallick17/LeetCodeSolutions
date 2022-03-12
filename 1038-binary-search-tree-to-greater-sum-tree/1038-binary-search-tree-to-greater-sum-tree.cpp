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
    int s;
    void solve(TreeNode* root){
        if(!root)return;
        solve(root->right);
        int tmp = root->val;
        root->val += s;
        s += tmp;
        solve(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root, int S=0) {
        solve(root);
        return root;
    }
};