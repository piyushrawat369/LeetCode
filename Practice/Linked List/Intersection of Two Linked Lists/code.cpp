/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode *currA = headA, *currB = headB;

        while(currA){
            currA = currA->next;
            a++;
        }
        while(currB){
            currB = currB->next;
            b++;
        }

        int k = abs(b-a);

        if(b > a){
            while(k--){
                headB = headB->next;
            }
        }
        else{
            while(k--){
                headA = headA->next;
            }
        }

        while(headA != headB && headA->next && headB->next){
            headA = headA->next;
            headB = headB->next;
        }

        if(headA != headB)
            return NULL;

        return headA;
    }
};
