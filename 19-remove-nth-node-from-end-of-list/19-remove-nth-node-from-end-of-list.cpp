/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int getLen(ListNode* head){
        int res=0;
        while(head){
            res++;
            head=head->next;
        }
        return res;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return NULL;
        n = getLen(head)-n;
        if(n==0)return head->next;
        ListNode* prev=NULL, *cur=head;
        
        while(n--){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        return head;
    }
};