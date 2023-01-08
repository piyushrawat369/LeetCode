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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode *p1 = head;
        ListNode *p2 = head;

        while(p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }

        p2 = p1, p1 = p1->next, p2->next = NULL;
        while(p1){
            ListNode *curr = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = curr;
        }
        
        p1 = head;
        
        
        while(p1){
            if(p1->val != p2->val)
                return false;
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return true;
    }
};
