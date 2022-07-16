// Time Complexity: O(N + M), where N and M are the lengths of the two lists.
// Space Complexity: O(1)


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head = new ListNode(-1) , *prehead = dummy_head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                dummy_head->next = l1;
                l1 = l1->next;
            }
            else
            {
                dummy_head->next = l2;
                l2 = l2->next;
            }
            dummy_head = dummy_head->next;
        }
        dummy_head->next = (l1 ? l1 : l2);
        return prehead->next;
    }
};
