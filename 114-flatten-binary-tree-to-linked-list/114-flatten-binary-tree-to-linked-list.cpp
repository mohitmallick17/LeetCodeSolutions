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
    void solve(TreeNode* root, TreeNode* &treeList){
        if(!root)return;
        auto l = root->left, r=root->right;
        treeList->right=root;
        treeList = treeList->right;
        treeList->left = treeList->right = NULL;
        solve(l,treeList);
        solve(r,treeList);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* res = new TreeNode(-1);
        TreeNode* head = res;
        solve(root, res);
        root=head->right;
    }
};