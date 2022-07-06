ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        first->next = swapPairs(first->next->next);
        
        second->next = first;
        
        return second;
    }
