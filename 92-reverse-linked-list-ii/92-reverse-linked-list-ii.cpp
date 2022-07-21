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
    ListNode* reverse(ListNode* l){
        ListNode* prev=NULL, *next=NULL, *cur=l;
        
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode *l=NULL, *r=NULL, *cur=head, *prev=NULL;
        int c=1;
        while(cur){
            if(c == left)
                l=cur;
            else if(c == right)
                r=cur;
            c++;
            if(l==NULL)
                prev=cur;
            cur=cur->next;
        }
        ListNode* rtemp = r->next;
        if(prev)prev->next=NULL;
        r->next=NULL;
        reverse(l);
        if(prev)prev->next=r;
        l->next = rtemp;
        
        if(l==head)
            return r;
        
        return head;
    }
};