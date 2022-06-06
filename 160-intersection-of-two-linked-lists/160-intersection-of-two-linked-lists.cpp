/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLen(ListNode *head){
        int res=0;
        while(head){
            res++;
            head=head->next;
        }
        return res;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=getLen(headA), l2=getLen(headB);
        if(l1==0 or l2==0)return NULL;
        if(l2 > l1){
            swap(headA, headB); // ensure len(A) >= len(B)
            swap(l1, l2);
        }
        for(int i=0;i<l1-l2 and headA;i++)
            headA=headA->next;
        // cout << l1 << ' ' << l2 << '\n';
        // cout << (headA->val) << ' ' << (headB->val);
        while(headA and headB){
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};