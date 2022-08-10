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
    
    TreeNode* solve(int start, int end, vector<int>& v){
        if(start > end)return NULL;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(start, mid-1, v);
        root->right = solve(mid+1, end, v);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
};