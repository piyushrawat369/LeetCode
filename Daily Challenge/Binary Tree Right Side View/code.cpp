class Solution {
public:
    vector<int> v;
    map<int, int> m;
    int height;
    
    void rightView(TreeNode* root){
        if(root == nullptr){
            return;
        }
        height = 1;
        TreeNode* ptr = root;
        
        while(root != nullptr){
            v.push_back(root->val);
            
            if(root->right != nullptr){
                root = root->right;
                height++;
            }
            else{
                if(root->left != nullptr){
                    root = root->left;
                    height++;
                }
                else{
                    break;
                }
            }
            
        }
    }
    
    void travel(TreeNode* root, int h = 1, bool t = true){
        if(root == nullptr){
            return;
        }
        if(h > height){
            if(t == true && m[h] == 0){
                v.push_back(root->val);
                m[h] = 1;
            }
        }
        if(root->left != nullptr && root->right != nullptr){
            travel(root->right, h+1, true);
            travel(root->left, h+1, false);
        }
        if(root->left != nullptr && root->right == nullptr){
            travel(root->left, h+1, true);
        }
        if(root->left == nullptr && root->right != nullptr){
            travel(root->right, h+1, true);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        rightView(root);
        travel(root);
        return v;
    }
};
