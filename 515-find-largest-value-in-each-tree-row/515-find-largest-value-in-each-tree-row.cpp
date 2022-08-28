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
    void solve(TreeNode* root, int level, vector<int> &v){
        if(!root)return;
        
        if(v.size() == level)
            v.push_back(root->val);
        else{
            v[level] = max(v[level], root->val);
        }
        solve(root->left, level+1, v);
        solve(root->right, level+1, v);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        solve(root, 0, res);
        return res;
    }
};