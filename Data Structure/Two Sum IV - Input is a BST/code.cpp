class Solution {
public:
    vector<int> v;
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int start = 0;
        int end = v.size()-1;
        while(end > start){
            if(v[start] + v[end] == k)
                return true;
            else if(v[start] + v[end] > k)
                end--;
            else
                start++;
        }
        return false;
    }
};
