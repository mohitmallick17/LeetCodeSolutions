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
    int widthOfBinaryTree(TreeNode* root) {
        long long res=1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        /*
        For a tree (0 indexed):
        left child: 2*i + 1
        right child 2*i + 2
        
        For a tree (1 indexed):
        left child: 2*i
        right child 2*i + 1      
        
        */
        
        while(!q.empty()){
            int size=q.size();
            long long begin_node = q.front().second;
            long long end_node = q.back().second;
            res = max(res, end_node - begin_node + 1);
            while(size--){
                auto front = q.front();
                q.pop();
                auto node = front.first;
                long long idx = front.second - begin_node;
                
                if(node->left)
                    q.push({node->left, 2*idx + 1});
                if(node->right)
                    q.push({node->right, 2*idx + 2});
            }
        }
        return res;
    }
};