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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int left_most;

        while(!q.empty()){
            TreeNode* ptr = q.front();
            q.pop();

            left_most = ptr->val;

            if(ptr->right)
                q.push(ptr->right);

            if(ptr->left)
                q.push(ptr->left);
        }
        return left_most;
    }
};
