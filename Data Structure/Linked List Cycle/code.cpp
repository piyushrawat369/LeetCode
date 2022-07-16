// Time Complexities: O(n)
// Space Complexities: O(1)


bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;;
        
        
        while(slow != fast){
            if(fast == nullptr || fast->next == nullptr)
                return false;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
