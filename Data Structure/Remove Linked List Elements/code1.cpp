// Approach (Recursive)

// Time Complexity: O(N), where N = length of the list. We visit each element only once in the worst case.
// Space Complexity: O(1)


ListNode* removeElements(ListNode* head, int v) {
        if(head == NULL) {
            return head;
        }
        if(head->val == v) {
            ListNode* temp = head->next;
            head->next = NULL;
            delete(head);
            return removeElements(temp , v);
        }
        head->next = removeElements(head->next , v);
        return head;
    }
