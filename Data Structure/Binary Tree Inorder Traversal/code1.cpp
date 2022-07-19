vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *curr = root, *node;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            if (!st.empty()) {
                node = st.top();
                st.pop();
                res.push_back(node->val);
                curr = node->right;
            }
        }
        return res;
    }
