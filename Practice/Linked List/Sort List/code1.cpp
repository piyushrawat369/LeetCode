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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;

        vector<int> a;
        ListNode *cur = head;

        while(cur){
            a.push_back(cur->val);
            cur = cur->next;
        }

        sort(a.begin(), a.end());

        int i = 0;
        cur = head;

        while(cur){
            cur->val = a[i++];
            cur = cur->next;
        }
        return head;
    }
};
