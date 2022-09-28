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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nh=new ListNode(0);
        nh->next=head;
        ListNode *slow=nh, *fast=nh;
        
        for(int i=0;i<=n;i++)
            fast=fast->next;
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        // cout << (slow->val);
        slow->next = (slow->next) ? slow->next->next : NULL;
        return nh->next;
    }
};