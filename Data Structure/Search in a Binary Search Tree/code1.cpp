// Approach(Recursive)


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int value) {
        if(root == nullptr)
            return root;
        if(value == root->val)
            return root;
        if(value < root->val)
            return searchBST(root->left, value);
        return searchBST(root->right, value);
    }
};
