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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddHead(0);
        ListNode evenHead(0);

        ListNode *odd = &oddHead;
        ListNode *even = &evenHead;

        for(int isOdd = 0; head; head = head->next){
            if(isOdd ^= 1){
                odd->next = head;
                odd = odd->next;
            }
            else{
                even->next = head;
                even = even->next;
            }
        }
        odd->next = evenHead.next;
        even->next = nullptr;

        return oddHead.next;
    }
};
