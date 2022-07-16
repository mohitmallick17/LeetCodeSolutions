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
    TreeNode* prev=new TreeNode(-1);
    void solve(TreeNode* root){
        if(!root)return;
        auto tmp_l = root->left;
        auto tmp_r = root->right;
        prev->right=root;
        prev=prev->right;
        prev->left=NULL;
        solve(tmp_l);
        solve(tmp_r);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prevHd=prev;
        solve(root);
        root=prevHd->right;
    }
};