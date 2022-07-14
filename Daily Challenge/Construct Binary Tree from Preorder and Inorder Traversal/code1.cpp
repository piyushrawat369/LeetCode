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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& root, int left, int right){
        if(left > right) return nullptr;
        
        int pivot = left;
        while(inorder[pivot] != preorder[root])  pivot++;
        
        root++;
        
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = helper(preorder, inorder, root, left, pivot-1);
        newNode->right = helper(preorder, inorder, root, pivot+1, right);
        
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = 0;
        return helper(preorder, inorder, root, 0, inorder.size()-1);
    }
};
