// Approach(Iterative)


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int value) {
        while(root != NULL)
        {
            if(root->val == value)
                return root;
            if(root->val > value)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }
};
