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
    long long ans = INT_MIN;
    long long s;
    
    long long solve(TreeNode* root){
        if(!root)return 0;
        long long lsum = solve(root->left);
        long long rsum = solve(root->right);
        int subtree_sum = root->val + lsum + rsum;
        
        ans = max(ans, subtree_sum*(s-subtree_sum));
        
        return lsum + rsum + root->val;
    }
    long long getSum(TreeNode* root){
        if(!root)return 0;
        long long lsum = solve(root->left);
        long long rsum = solve(root->right);
        return lsum + rsum + root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        s = getSum(root);
        solve(root);
        return ans%1000000007;
    }
};