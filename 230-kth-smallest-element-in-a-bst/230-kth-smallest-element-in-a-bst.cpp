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
    int count=0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        auto l = kthSmallest(root->left, k);
        count++;
        if(count==k)return root->val;
        auto r = kthSmallest(root->right, k);
        if(l != -1)return l;
        return r;
    }
};