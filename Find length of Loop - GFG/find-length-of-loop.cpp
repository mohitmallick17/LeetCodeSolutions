// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node* getCycleHead(Node* head){
    if(!head or !head->next)return NULL;
    Node* slow=head, *fast=head;
    
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        // cout << "gg ";
        if(slow==fast)break;
    }
    if(slow!=fast)return NULL; // No cycle
    return fast;
}
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head){
    Node* cycleHead = getCycleHead(head);
    if(!cycleHead)return 0;
    int count = 0;
    Node* cur=cycleHead;
    do{
        // cout << "loop ";
        cur=cur->next;
        count++;
    }while(cur != cycleHead);
    return count;
}