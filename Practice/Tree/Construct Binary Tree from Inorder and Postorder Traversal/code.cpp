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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> pos;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            pos[inorder[i]] = i;
        }

        TreeNode* root = NULL;
        for(int i=n-1; i>=0; i--){
            int num = postorder[i], p = pos[num];
            TreeNode *temp = new TreeNode(num);

            if(i == n-1){
                root = temp;
                continue;
            }
            TreeNode* node = root, *prev = NULL;
            
            while(node){
                prev = node;
                if(pos[node->val] > p) 
                    node = node->left;
                else
                    node = node->right;
            }
            node = temp;
            if(pos[prev->val] > p)  prev->left = temp;
            else    prev->right = temp;
        }
        return root;
    }
};
