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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        if(root == nullptr)
            return ans;

        q.push({root, 0});

        while(!q.empty()){
            TreeNode* ptr = q.front().first;
            int row = q.front().second;
            q.pop();

            mp[row] = ptr->val;

            if(ptr->left)
                q.push({ptr->left, row+1});
            if(ptr->right)
                q.push({ptr->right, row+1});
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
