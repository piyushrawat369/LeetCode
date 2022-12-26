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
    void generate(vector<TreeNode*> &ret, int left, int right){
        if(left > right){
              ret.push_back(NULL);
              return;
        }
        for(int i=left; i<=right; i++){
            vector<TreeNode*> lefts;
            generate(lefts, left, i-1);

            vector<TreeNode*> rights;
            generate(rights, i+1, right);

            for(int u=0; u<lefts.size(); u++){
                for(int v=0; v<rights.size(); v++){
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[u];
                    root->right = rights[v];
                    ret.push_back(root);
                }
            }
        }
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        generate(res, 1, n);
        return res; 
    }
};
