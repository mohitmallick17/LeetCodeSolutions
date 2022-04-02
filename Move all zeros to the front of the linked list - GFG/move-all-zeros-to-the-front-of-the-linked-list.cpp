// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

// function to displaying nodes
void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);

    }
}
// } Driver Code Ends


//User function Template for C++
/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
// Move Zeros to the front of the list
void moveZeroes(struct Node **head){
    Node* hd=(*head);
    Node* hz = new Node(-1), *hnz=new Node(-1);
    Node* z = hz, *nz=hnz;
    Node* cur = hd;
    
    while(cur){
        if(cur->data == 0){
            z->next = cur;
            z=z->next;
        }else{
            nz->next=cur;
            nz=nz->next;
        }
        cur = cur->next;
    }
    z->next=NULL;
    nz->next=NULL;
    
    if(!hz->next)
        (*head) = hnz->next;
    else if(!hnz->next)
        (*head) = hz->next;
    else{
        z->next=hnz->next;
        (*head) = hz->next;
    }
}