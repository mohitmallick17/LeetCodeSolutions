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
    int sum = 0;
    void convert(TreeNode* cur) {
        if (cur == NULL) return;
        convert(cur->right);
        cur->val += sum;
        sum = cur->val;
        convert(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }
};