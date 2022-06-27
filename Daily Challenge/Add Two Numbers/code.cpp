ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* temp = nullptr;
        
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            ListNode* node = new ListNode(sum % 10);
            
            carry = sum / 10;
            
            if(head == nullptr){
                temp = head = node;
            }
            else{
                temp->next = node;
                temp = temp->next;
            }
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return head;
        
    }
