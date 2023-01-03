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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        int n = 1;
        auto curr = head;
        for(; curr->next; curr = curr->next)
            ++n;
        
        curr->next = head;

        auto tail = head;
        k = n - k % n;
        curr = head;
        
        for(int i=0; i<k; curr = curr->next, ++i){
            tail = curr;
        }
        tail->next = NULL;
        return curr;
    }
};
