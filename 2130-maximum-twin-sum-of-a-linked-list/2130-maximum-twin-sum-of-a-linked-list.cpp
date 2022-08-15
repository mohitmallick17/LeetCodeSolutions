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
    ListNode* reverseLL(ListNode* head){
        ListNode* cur=head, *prev=NULL;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* midNode = reverseLL(slow);
        int res = 0;
        while(midNode){
            res = max(res, head->val + midNode->val);
            midNode = midNode->next;
            head = head->next;
        }
        return res;
    }
};