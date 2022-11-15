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
    int op = 0;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + height(root->left);
    }
    
    void solve(TreeNode* root,int h){
        if(h == 2){
            if(root->left != NULL) op++;
            if(root->right != NULL) op++;
            return;
        }
        solve(root->left,h-1);
        solve(root->right,h-1);
    }
    
    int countNodes(TreeNode* root) {
        int h = height(root);
        if(h == 0) return 0;
        if(h == 1) return 1;
        int ans = pow(2,h-1) - 1;
        solve(root,h);
        return ans + op;
    }
};
