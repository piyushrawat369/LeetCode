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
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX; // Initialize prev value based on level parity

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Check if current node violates conditions
                if ((level % 2 == 0 && (temp->val % 2 == 0 || temp->val <= prev)) || 
                    (level % 2 != 0 && (temp->val % 2 != 0 || temp->val >= prev)))
                    return false;

                prev = temp->val;

                if (temp->left) 
                    q.push(temp->left);
                if (temp->right) 
                    q.push(temp->right);
            }
            level++;
        }
        return true;
    }
};
