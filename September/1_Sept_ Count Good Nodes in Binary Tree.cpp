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
    int ans = 0;
    void goodNodes(TreeNode* root,int mx){
        if(root == NULL) return;
        if(root->val >= mx){
            ans++;
            mx = root->val;
        }
        goodNodes(root->left,mx);
        goodNodes(root->right,mx);
        
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int mx = root->val;
        goodNodes(root,mx);
        return ans;
    }
};
