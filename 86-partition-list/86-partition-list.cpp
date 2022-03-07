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
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode* d1 = new ListNode(-1), *d2=new ListNode(-1);
        
        ListNode* r1=d1, *r2=d2;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                r1->next=cur;
                r1=r1->next;
            }
            else{
                r2->next=cur;
                r2=r2->next;
            }
            cur=cur->next;
        }
        r2->next = NULL;
        if(d1->next){
            r1->next = d2->next;
        }else
            d1=d2;
        return d1->next;
    }
};