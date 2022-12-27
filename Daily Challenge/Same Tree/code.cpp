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
public:
    bool valid = true;    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return valid;
    }
    void dfs(TreeNode* p, TreeNode* q){
        if(p == NULL && q != NULL) valid = false;
        else if(p != NULL && q == NULL) valid = false;
        if(p == NULL || q == NULL) return;

        if(p->val != q->val) valid = false;

        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }
};
