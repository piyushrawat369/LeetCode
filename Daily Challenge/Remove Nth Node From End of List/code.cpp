ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow;
        ListNode* fast;
        
        slow = head;
        fast = head;
        
        while(n){
            fast = fast->next;
            n--;
        }
        
        if(fast == nullptr){
            head = head->next;
            return head;
        }
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        if(slow->next && slow->next->next){
            slow->next = slow->next->next;
        }
        else{
            slow->next = nullptr;
        }
        return head;
    }
