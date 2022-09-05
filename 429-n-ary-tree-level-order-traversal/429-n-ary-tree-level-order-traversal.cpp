/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int> cur;
            while(size--){
                auto node = q.front();
                q.pop();
                cur.push_back(node->val);
                for(auto &c:node->children)
                    q.push(c);
            }
            if(!cur.empty())res.push_back(cur);
        }
        return res;
    }
};