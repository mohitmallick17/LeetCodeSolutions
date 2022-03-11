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
    int getSize(ListNode* n){
        int l=0;
        while(n){
            l++;
            n = n->next;
        }
        return l;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getSize(head);
        if(k==0 or len<2 or k%len == 0)return head;
        k %= len;
        ListNode* cur = head, *prev=NULL;
        for(int i=0;i<len-k;i++){
            prev=cur;
            cur = cur->next;
        }
        ListNode* newHd = cur;
        if(prev)
            prev->next = NULL;
        cur = newHd;
        while(cur->next)cur=cur->next;
        cur->next = head;
        return newHd;
    }
};