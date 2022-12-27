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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
         if (!root)
            return {};
        
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *> nodes;
        
        nodes.push(root);
        
        std::vector<int> level_result;
        bool right_to_left = false;

        while(!nodes.empty()) {            

            const int nodes_at_current_level = nodes.size();
            for(int i = 0; i < nodes_at_current_level; i++) {

                TreeNode *node = nodes.front();            
                nodes.pop();
                level_result.push_back(node->val);

                if (node->left)
                    nodes.push(node->left);

                if (node->right)
                    nodes.push(node->right);
            }
            
            if (right_to_left)
                std::reverse(level_result.begin(), level_result.end());
            
            right_to_left ^= true;                
            
            result.push_back(level_result);
            level_result.clear();
        }
        
        return result; 
        
    }
};
