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
        ListNode* d1 = new ListNode(-1), *d3=new ListNode(-1); // , *d2=new ListNode(-1), 
        
        ListNode* r1=d1, *r3=d3; //*r2=d2, 
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                r1->next=cur;
                r1=r1->next;
            }
            // else if(cur->val == x){
            //     r2->next=cur;
            //     r2 = r2->next;
            // }
            else{
                r3->next=cur;
                r3=r3->next;
            }
            cur=cur->next;
        }
        // if(d2->next){
        //     r3->next=NULL; // end of list
        //     r2->next = d3->next;
        // }else
        //     d2=d3;
        r3->next = NULL;
        if(d1->next){
            r1->next = d3->next;
        }else
            d1=d3;
        return d1->next;
    }
};