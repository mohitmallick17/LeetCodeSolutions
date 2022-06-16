/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur==NULL)
                res += "# ";
            else{
                res += to_string(cur->val) + " ";
                q.push(cur->left);
                q.push(cur->right);
            }                
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;
        stringstream ss(data);
        string str;
        getline(ss, str, ' ');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            getline(ss, str, ' '); // left
            if(str=="#")
                front->left=NULL;
            else{
                front->left = new TreeNode(stoi(str));
                q.push(front->left);
            }
            
            getline(ss, str, ' '); // right
            if(str=="#")
                front->right=NULL;
            else{
                front->right = new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));