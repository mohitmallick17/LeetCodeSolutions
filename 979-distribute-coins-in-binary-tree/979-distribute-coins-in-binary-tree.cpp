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
    int moves=0;
    int solve(TreeNode* root){
        if(!root)return 0;
        int left=solve(root->left), right=solve(root->right);
        moves += abs(left) + abs(right);
        
        int ret = root->val - 1 + left + right; // we give all extra/debt coins to parent
        // ans = total_coins_root_has - 1 (bcoz each node need 1 coin) + left + right (extra/debt of children)
        
        return ret;
    }
public:
    int distributeCoins(TreeNode* root) {
        solve(root);
        return moves;
    }
};