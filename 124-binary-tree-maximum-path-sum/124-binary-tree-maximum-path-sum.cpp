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
    int solve(TreeNode* root, int &ans){        
        if(!root)return 0;
        
        int lsum = solve(root->left, ans);
        int rsum = solve(root->right, ans);
        int nbrSum = 0;
        if(lsum>0)nbrSum+=lsum;
        if(rsum>0)nbrSum+=rsum;
        ans = max(ans, root->val+nbrSum);
        
        return max({root->val, root->val + lsum, root->val + rsum});
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans=INT_MIN;
        solve(root, ans);
        return ans;        
    }
};