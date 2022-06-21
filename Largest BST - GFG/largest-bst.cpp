// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct nodeData{
    bool isBST;
    int size;
    int mn;
    int mx;
    nodeData(bool flag, int sz, int minn, int maxx){
        isBST=flag;
        size=sz;
        mn=minn;
        mx=maxx;
    }
};

class Solution{
    nodeData solve(Node* root){
        if(!root)return nodeData(true, 0, INT_MAX, INT_MIN);
        
        nodeData l = solve(root->left);
        nodeData r = solve(root->right);
        int cur = root->data;
        // cout << cur << "-\n" << l.isBST << ' ' << l.size << ' ' << l.mn << ' ' << l.mx << "\n" << r.isBST << ' ' << r.size << ' ' << r.mn << ' ' << r.mx << "\n";
        if(l.isBST and r.isBST and cur > l.mx and cur < r.mn){
            return nodeData(true, l.size + r.size + 1, min(l.mn, cur), max(r.mx, cur));
        }
        return nodeData(false, max(l.size, r.size), 0, 0);
    }
public:
   int largestBst(Node *root){
    return solve(root).size;
   }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends