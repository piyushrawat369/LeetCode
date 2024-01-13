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
    unordered_map<int, vector<int>> adj;

    int amountOfTime(TreeNode* root, int start) {
        graph_adj(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        int time = -1;

        while(!q.empty()){
            ++time;
            int size = q.size();
            for(int i=0; i<size; i++){
                int cur = q.front();
                q.pop();

                visited.insert(cur);
                for(auto it: adj[cur]){
                    if(!visited.count(it)){
                        q.push(it);
                    }
                }

            }
        }
        return time;
    }

    void graph_adj(TreeNode* root){
        if(!root)   return;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }

        graph_adj(root->left);
        graph_adj(root->right);
    }
};
