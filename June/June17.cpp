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
    int cam;
    
    int dfs(TreeNode* root){
        if(root == NULL){
            return 2;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == 0 || right == 0){
            cam++;
            return 1;
        }
        if(left == 1 || right == 1){
            return 2;
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        cam = 0;
        int ans = dfs(root);
        if(ans == 0){
            cam++;
        }
        return cam;
    }
};
