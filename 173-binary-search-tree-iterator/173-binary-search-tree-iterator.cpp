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
class BSTIterator {
    stack<pair<int, TreeNode*>> stk;
public:
    BSTIterator(TreeNode* root) {
        stk.push({1, root});
    }
    
    int next() {
        while(!stk.empty()){
            int state=stk.top().first;
            TreeNode* node=stk.top().second;
            
            if(state==1){
                stk.top().first++;
                if(node->left)stk.push({1, node->left});
            }else if(state==2){
                stk.top().first++;
                if(node->right)stk.push({1, node->right});
                return node->val;
            }else if(state==3){
                stk.pop();
            }
        }
        return -1;
    }
    
    bool hasNext() {
        while(!stk.empty() and stk.top().first==3)
            stk.pop();
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */