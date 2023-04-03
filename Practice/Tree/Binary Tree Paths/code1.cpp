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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, paths, "");
        return paths;
    }

    void dfs(TreeNode* root, vector<string>& paths, string path){
        if(root){
            path += to_string(root->val);
            if(!root->left && !root->right){
                paths.push_back(path);
            }
            else{
                path += "->";
                dfs(root->left, paths, path);
                dfs(root->right, paths, path);
            }
        }
    }
};
