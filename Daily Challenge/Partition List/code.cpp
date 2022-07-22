class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyOne = new ListNode(-1);
        ListNode* dummyTwo = new ListNode(-1);
        ListNode* tailOne = dummyOne;
        ListNode* tailTwo = dummyTwo;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            if(temp->val < x){
                tailOne = addNodeAtLast(temp, tailOne);
            }
            else{
                tailTwo = addNodeAtLast(temp, tailTwo);
            }  
        }
        tailOne->next = dummyTwo->next;
        return dummyOne->next;
    }
    
    ListNode* addNodeAtLast(ListNode* temp, ListNode* tail){
        tail->next = temp;
        tail = tail->next;
        return tail;
    }
};
