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
    TreeNode* addOneRow(TreeNode* root, int val, int depth, int cur=1) {
        if(!root)return NULL;
        
        if(depth==1){
            auto node = new TreeNode(val);
            node->left = root;
            
            return node;
        }
        
        if(cur == depth-1){
            auto nl = new TreeNode(val);
            nl->left = root->left;
            root->left = nl;
            
            
            auto nr = new TreeNode(val);
            nr->right = root->right;
            root->right = nr;
            
            return root;
        }
        
        auto l = addOneRow(root->left, val, depth, cur+1);
        auto r = addOneRow(root->right, val, depth, cur+1);
        root->left=l;
        root->right=r;
        
        return root;
    }
};