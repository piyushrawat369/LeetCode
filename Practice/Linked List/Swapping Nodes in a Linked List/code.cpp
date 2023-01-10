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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head;
        int n = 0;

        while(ptr){
            n++;
            ptr = ptr->next;
        }
        int x = (n - k);
        k -= 1;

        ListNode *a = head;
        ListNode *b = head;
        while(k--){
            a = a->next;
        }
        while(x--){
            b = b->next;
        }
        
        int m = b->val;
        b->val = a->val;
        a->val = m;
        
        return head;
    }
};
