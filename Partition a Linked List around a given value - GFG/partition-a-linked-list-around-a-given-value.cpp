// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    Node* r1=new Node(0), *r2=new Node(0), *r3=new Node(0);
    Node *l1=r1, *l2=r2, *l3=r3;
    
    while(head){
        Node* nxt=head->next;
        if(head->data < x){
            l1->next=head;
            l1=l1->next;
            l1->next=NULL;
        }else if(head->data == x){
            l2->next=head;
            l2=l2->next;
            l2->next=NULL;
        }else{
            l3->next=head;
            l3=l3->next;
            l3->next=NULL;    
        }
        head=nxt;
    }
    if(r2->next)
        l2->next=r3->next;
    else
        r2->next=r3->next;
    if(r1->next)
        l1->next=r2->next;
    else
        r1->next=r2->next;
    return r1->next;
}