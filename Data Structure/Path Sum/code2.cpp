class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        return has(root, 0, sum);
    }
    bool has(TreeNode* root, int cur, int sum){
        if(root->left == nullptr && root->right == nullptr){
            return sum == cur + root->val;
        }
        cur += root->val;
        bool res = false;
        if(root->left != nullptr){
            res = has(root->left, cur, sum);
        }
        if(res) return true;
        
        if(root->right != nullptr){
            res = has(root->right, cur, sum);
        }
        
        return res;
    }
};
