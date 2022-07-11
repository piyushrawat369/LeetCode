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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == nullptr || k == 1){
            return head;
        }
        ListNode* fake = new ListNode(0);
        fake->next = head;
        
        ListNode* pre = fake;
        int i = 0;
        
        ListNode* p = head;
        while(p != nullptr){
            i++;
            if(i % k == 0){
                pre = reverse(pre, p->next);
                p = pre->next;
            }
            else{
                p = p->next;
            }
        }
        return fake->next;
          
    }
    ListNode* reverse(ListNode* pre, ListNode* next){
        ListNode* last = pre->next;
        ListNode* curr = last->next;
        
        while(curr != next){
            last->next = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = last->next;
        }
        return last;
    }
};
