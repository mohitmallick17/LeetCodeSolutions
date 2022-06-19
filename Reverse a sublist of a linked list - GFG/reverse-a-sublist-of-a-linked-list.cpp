// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    int getLen(Node* head){
        int l=0;
        while(head){
            l++;
            head=head->next;
        }
        return l;
    }
    Node* reverseLL(Node* head){
        Node* prev=NULL;
        while(head){
            Node* nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    public:
    Node* reverseBetween(Node* head, int start, int end){
        int len = getLen(head);
        Node* root = new Node(0);
        root->next=head;
        Node* prev=root, *nxt=NULL;
        for(int i=1;i<start;i++){
            prev=head;
            head=head->next;
        }
        int i=start;
        for(Node* cur=head;i<=end;i++){
            if(i==end){
                nxt=cur->next;
                cur->next=NULL;
            }else
                cur=cur->next;
        }
        Node* newTail = head;
        prev->next = reverseLL(head);
        newTail->next = nxt;
        return root->next;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends