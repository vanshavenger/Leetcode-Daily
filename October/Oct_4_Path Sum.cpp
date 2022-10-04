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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->right == NULL && root->left == NULL){
            targetSum -= root->val;
            if(targetSum == 0) return true;   
            return false;
        }
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum - root->val);
    }
};
