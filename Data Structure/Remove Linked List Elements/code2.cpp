// Approach (Iterative)

// Time Complexity: O(N), as we iterate the whole list once. N = length of the list
// Space Complexity: O(1)


ListNode* removeElements(ListNode* head, int v) {
    ListNode *dummy = new ListNode(-1) , *prev = dummy , *toDelete;
    dummy->next = head;
    while(head != NULL) {
        if(head->val == v) {
            toDelete = head;
            prev->next = head->next;
            head = head->next;
            toDelete->next = NULL;
        }
        else {
            toDelete = NULL;
            prev = head;
            head = head->next;
        }
        if(toDelete != NULL)
            delete(toDelete);
    }
    return dummy->next;
}
