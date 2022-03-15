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
    unordered_map<int, vector<TreeNode*>> dp;
    
    vector<TreeNode*> solve(int n){
        if(dp.find(n) != dp.end())
            return dp[n];
        
        vector<TreeNode*> res;
        
        for(int l=1;l<n;l+=2){
            int r = n-1-l;
            
            vector<TreeNode*> left = solve(l);
            vector<TreeNode*> right = solve(r);
            
            for(auto &lhs:left){
                for(auto &rhs:right){
                    res.push_back(new TreeNode(0, lhs, rhs));
                }
            }            
        }
        return dp[n]=res;        
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        // only odd no of N possible. 1(root) + n-1 combinations 
        if((n & 1) == 0)return {};
        
        // empty tree
        dp[0] = {};
        // tree with single node
        dp[1] = {new TreeNode(0)};
        
        // calculate
        return solve(n);;
    }
};