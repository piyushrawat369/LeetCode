// Time:  O(n * logk)
// Space: O(k)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy {0};
        auto *cur = &dummy;
            
        struct compare{
            bool operator()(const ListNode *a, const ListNode *b){
                return a->val > b->val; 
            }
        };
        
        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;
        
        for(const auto &n: lists){
            if(n){
                min_heap.emplace(n);
            }
        }
        
        while(!min_heap.empty()){
            auto *node = min_heap.top();
            min_heap.pop();
            
            cur->next = node;
            cur = cur->next;
            if(node->next){
                min_heap.emplace(node->next);
            }
        }
        return dummy.next;
    }

};
