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
    map<int, map<int, multiset<int>>> mp; // map = vertical : {horizontal: {multiset<>}}
    void solve(TreeNode* root, int v, int h){
        if(!root)return;
        mp[v][h].insert(root->val);
        solve(root->left, v-1, h+1);
        solve(root->right, v+1, h+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        solve(root, 0, 0);
        vector<vector<int>> res;
        for(auto &[k1, v1]:mp){
            vector<int> cur;
            for(auto &[k2, v2]:v1){
                for(auto x:v2)
                    cur.push_back(x);
            }
            if(cur.size())
                res.push_back(cur);
        }
        return res;
    }
};