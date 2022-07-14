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
    TreeNode* solve(int ps, int pe, int is, int ie, vector<int>& preorder, vector<int>& inorder, 
                    unordered_map<int, int>& inmp){
        if(ps > pe or is > ie)return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int index_at_inorder = inmp[root->val];
        int nums_in_left = index_at_inorder - is;
        root->left = solve(ps+1, ps+nums_in_left, is, index_at_inorder-1, preorder, inorder, inmp);
        root->right = solve(ps+nums_in_left+1, pe, index_at_inorder+1, ie, preorder, inorder, inmp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)mp[inorder[i]]=i;
        return solve(0,n-1,0,n-1,preorder,inorder,mp);
    }
};