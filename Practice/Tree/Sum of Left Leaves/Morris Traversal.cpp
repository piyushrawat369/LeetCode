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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        while(root != NULL){
            if(root->left == NULL){
                if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
                    sum += root->left->val;
                root = root->right;
            }
            else{
                TreeNode* temp = root->left;
                while(temp->right != NULL && temp->right != root)
                    temp = temp->right;
                
                if(temp->right == NULL){
                    temp->right = root;
                    root = root->left;
                }
                else{
                    temp->right = NULL;
                    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
                        sum += root->left->val;
                    root = root->right;
                }
            }
        }
        return sum;
    }
};
