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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        int Sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            Sum = 0;
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                Sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return Sum;
    }
};