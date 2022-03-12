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
    int index=0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int ub=INT_MAX){
        if(index==preorder.size() or preorder[index] > ub)return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, ub);
        return root;
    }
};