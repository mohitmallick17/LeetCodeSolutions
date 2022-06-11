class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key=k;
        val=v;
        prev=next=NULL;
    }
};

class LRUCache {
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int cap;
    
    void deleteNode(Node* node){
        Node* pre=node->prev;
        Node* nxt=node->next;
        
        pre->next=nxt;
        nxt->prev=pre;
    }
    
    void insertNode(Node *node){
        Node* nxt=head->next;
        
        node->prev=head;
        head->next=node;
        
        node->next=nxt;
        nxt->prev=node;
        
    }
public:
    LRUCache(int capacity){
        cap=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key){
        if(mp.find(key) == mp.end())return -1;;
        Node* delNode = mp[key];
        int val=delNode->val;
        deleteNode(delNode);
        insertNode(delNode);
        
        return val;
    }
    
    void put(int key_, int value){

        if(mp.find(key_) != mp.end()) {
            Node* existingnode = mp[key_];
            mp.erase(key_);
            deleteNode(existingnode);
        }
        if(mp.size() == cap) {
          mp.erase(tail->prev->key);
          deleteNode(tail->prev);
        }
        
        insertNode(new Node(key_, value));
        mp[key_] = head->next; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */