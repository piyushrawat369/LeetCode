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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;

        while(l1){
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2);
            l2 = l2->next;
        }

        ListNode *head = nullptr;
        int carry = 0;
        
        while(carry || !s1.empty() || !s2.empty()){
            if(!s1.empty()){
                carry += s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()){
                carry += s2.top()->val;
                s2.pop();
            }

            ListNode *node = new ListNode(carry%10);
            node->next = head;
            head = node;
            carry /= 10;
        }
        return head;
    }
};
