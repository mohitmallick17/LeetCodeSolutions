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
    
    // c=-1 need camera
    // c=0 have camera
    // c=1 already covered
    
    int count=0;
    int solve(TreeNode* root, TreeNode* asli_root){
        if(!root)return 1;
        
        int lc = solve(root->left, root);
        int rc = solve(root->right, root);
        
        if(lc==-1 or rc==-1){
            // any of my child needs camera:
            count++;
            return 0;            
        }
        // if I am covered by child
        if(lc==0 or rc==0)
            return 1;
        
        // if I am the top-most root and not covered
        if(root==asli_root){
            count++;
            return 0;
        }
        
        // otherwise ask for camera
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        solve(root, root);
        return count;
    }
};