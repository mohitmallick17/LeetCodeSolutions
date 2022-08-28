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
    vector<TreeNode*> solve(int low, int high){
        if(low > high)return {NULL};
        vector<TreeNode*> res;
        
        for(int r=low;r<=high;r++){
            // root val = r
            auto left_subtree = solve(low, r-1);
            auto right_subtree = solve(r+1, high);
            
            for(auto &left:left_subtree){
                for(auto &right:right_subtree){
                    TreeNode* root = new TreeNode(r);
                    root->left = left;
                    root->right = right;
                    
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};