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
    int gcSum(TreeNode* node){
        int s=0;
        if(node->left){
            if(node->left->left)
                s += node->left->left->val;
            if(node->left->right)
                s += node->left->right->val;
        }
        if(node->right){
            if(node->right->left)
                s += node->right->left->val;
            if(node->right->right)
                s += node->right->right->val;
        }
        return s;
    }
public:
    int sumEvenGrandparent(TreeNode* root){
        int Sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(((node->val) & 1)==0)
                Sum += gcSum(node);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return Sum;
    }
};