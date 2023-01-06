/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* head;

    TreeNode* func(int l, int r){
        if(l > r)
            return nullptr;

        const int m = (l + r) / 2;

        TreeNode* lef = func(l, m-1);

        TreeNode* root = new TreeNode(head->val);
        root->left = lef;
        
        head = head->next;

        root->right = func(m+1, r);

        return root;
    }

    int length(ListNode* head){
        ListNode* curr = head;
        int length = 0;
        while(curr){
            ++length;
            curr = curr->next;
        }
        return length;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        return func(0, length(head)-1);
    }

};
