ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* last = head;
        ListNode* cur = head->next;
        
        while(cur != NULL){
            if(cur->val == last->val){
                //remove cur
                last->next = cur->next;
            }else{
                //update last only if cur isn't duplicate
                last = cur;
            }
            cur = cur->next;
        }
        
        return head;
    }
