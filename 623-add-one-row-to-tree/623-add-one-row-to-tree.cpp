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
    void solve(TreeNode* root, int curD, int val, int depth){
        if(!root)return;
        if(curD == depth){
            TreeNode* lc = new TreeNode(val);
            lc->left = root->left;
            TreeNode* rc = new TreeNode(val);
            rc->right = root->right;
            
            root->left = lc;
            root->right = rc;
            return;
        }
        solve(root->left, curD+1, val, depth);
        solve(root->right, curD+1, val, depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *nr = new TreeNode(val);
            nr->left=root;
            return nr;
        }
        solve(root, 1, val, depth-1);
        return root;
    }
};