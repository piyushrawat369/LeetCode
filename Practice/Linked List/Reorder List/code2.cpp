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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;

        ListNode* ptr = head;

        while(ptr->next->next){
            ptr = ptr->next;
        }

        ptr->next->next = head->next;
        head->next = ptr->next;
        ptr->next = nullptr;

        reorderList(head->next->next);
    }
};
