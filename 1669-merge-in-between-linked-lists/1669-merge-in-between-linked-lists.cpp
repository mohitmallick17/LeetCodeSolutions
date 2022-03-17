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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h = new ListNode(0, list1);
        ListNode* cur = h;;
        b -= a;
        while(a > 0)
            cur = cur->next, a--;
        ListNode* orig = cur->next;
        cur->next = list2;
        while(cur->next)
            cur = cur->next;
        while(b>0)
            orig = orig->next, b--;
        cur->next = orig->next;
        return h->next;
    }
};