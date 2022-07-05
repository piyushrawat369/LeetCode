// Time:  O(n * logk)
// Space: O(logk)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists, 0, lists.size()-1);
    }

private:
    ListNode* mergeKListsHelper(const vector<ListNode*>& lists, int begin, int end){
        if(begin > end){
            return nullptr;
        }
        if(begin == end){
            return lists[begin];
        }
        return mergeTwoLists(mergeKListsHelper(lists, begin, (begin+end)/2), mergeKListsHelper(lists, (begin+end)/2 +1, end));
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy{0};
        auto curr = &dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1? l1: l2;
        return dummy.next;;
    }

};
