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
class FindElements {
    TreeNode* r;
    unordered_set<int> s;
    unordered_map<int, bool> cache;
    TreeNode* solve(TreeNode* root, TreeNode* p, char dir){
        if(!root)return NULL;
        if(!p)root->val=0;
        else{
            if(dir=='L')root->val = 2*p->val + 1;
            else root->val = 2*p->val + 2;
        }
        solve(root->left, root, 'L');
        solve(root->right, root, 'R');
        
        s.insert(root->val);
        return root;
    }
public:
    FindElements(TreeNode* root) {
        r=solve(root,NULL,'.');
    }
    
    bool find(int target) {
        if(target==0)return true;
        if(cache.find(target) != cache.end())return cache[target];
        return cache[target] = s.find(target) != s.end() and (find((target-1)/2) or find((target-2)/2));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */