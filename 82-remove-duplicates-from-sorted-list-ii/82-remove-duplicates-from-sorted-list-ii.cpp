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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* l1 = head;
        while(l1){
            if(!l1->next or l1->next->val != l1->val){
                cur->next=l1;
                cur=cur->next;
            }else{
                while(l1->next and l1->val == l1->next->val)
                    l1 = l1->next;
            }
            l1 = l1->next;
        }
        cur->next = NULL;
        return dummy->next;
    }
};