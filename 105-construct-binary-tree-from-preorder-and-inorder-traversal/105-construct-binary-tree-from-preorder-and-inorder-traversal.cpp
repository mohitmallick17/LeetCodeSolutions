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
    TreeNode* solve(int ps, int pe, int is, int ie, vector<int>& preorder, 
                    vector<int>& inorder, unordered_map<int, int> &imap){
        if(ps > pe or is > ie)return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int in_idx = imap[preorder[ps]];
        int cnt_elements_to_left = in_idx - is;
        root->left = solve(ps+1, ps+cnt_elements_to_left, is, in_idx-1, preorder, inorder, imap);
        root->right = solve(ps+cnt_elements_to_left+1, pe, in_idx+1, ie, preorder, inorder, imap);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int, int> imap;
        for(int i=0;i<inorder.size();i++)
            imap[inorder[i]] = i;
        return solve(0, n-1, 0, n-1, preorder, inorder, imap);
    }
};