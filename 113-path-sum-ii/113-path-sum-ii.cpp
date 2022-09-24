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
    vector<vector<int>> res;
    void solve(TreeNode* root, int t, vector<int> &cur){
        if(!root)return;
        cur.push_back(root->val);
        t -= (root->val);
        if(!root->left && !root->right){
            if(t==0)res.push_back(cur);
        }
        solve(root->left,t, cur);
        solve(root->right,t, cur);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> c;
        solve(root, targetSum, c);
        return res;
    }
};