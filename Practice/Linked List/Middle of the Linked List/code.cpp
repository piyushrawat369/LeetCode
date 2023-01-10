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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *ptr = head;
        ListNode dummy(0);
        ListNode *ans = &dummy;
        while(ptr){
            n++;
            ptr = ptr->next;
        }
        int x = (n/2);
        ptr = head;
        while(x--){
            ptr = ptr->next;
        }
        ans->next = ptr;
        return dummy.next;
    }
};
