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
    bool isLeafNode(TreeNode* &root){
        return (!root->left and !root->right);
    }
    bool visit(TreeNode* root, unordered_map<int, TreeNode*> &mp, int left=INT_MIN, int right=INT_MAX){
        if(!root)return true;
        if(root->val <= left or root->val >= right)return false;
        
        if(isLeafNode(root)){
            auto it=mp.find(root->val);
            // tree exists with root val=cur_leaf_value && it->second (iterator value) is not same as cur node
            // ex. in case of tree with only root node, 5. find(5) -> gives the same node!
            if(it != mp.end() and it->second != root){
                root->left=it->second->left;
                root->right=it->second->right;
                mp.erase(it);
            }
        }
        return visit(root->left, mp, left, root->val) and visit(root->right, mp, root->val, right);
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> count;
        
        for(auto &cur:trees){
            mp[cur->val]=cur;
            count[cur->val]++;
            if(cur->left)count[cur->left->val]++;
            if(cur->right)count[cur->right->val]++;
        }
        
        for(auto &cur:trees){
            if(count[cur->val]==1){
                bool res = visit(cur, mp);
                if(res and mp.size()==1)
                    return cur;
                return NULL;
            }
        }
        return NULL;
    }
};