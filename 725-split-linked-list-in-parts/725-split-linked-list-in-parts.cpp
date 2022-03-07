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
    int getListLen(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getListLen(head);   
        vector<ListNode*> res(k);
        int per_head = len/k;
        int balance = len -(per_head*k);
        ListNode* cur = head;
        
        for(int i=0;i<k and cur;i++){
            res[i] = cur;
            for(int j=1;(j < per_head + (i<balance)) and cur;j++){
                cur = cur->next;
            }
            if(cur){
                ListNode* nxt = cur->next;
                cur->next = NULL;
                cur = nxt;
            }
            
        }
        return res;
    }
};