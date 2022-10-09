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
    bool solve(TreeNode*& root,int& k,unordered_set<int>& se){
        if(root == NULL) return false;
        if(se.find(k - root->val) != se.end()) return true;
        se.insert(root->val);
        bool left = solve(root->left,k,se);
        bool right = solve(root->right,k,se);
        return left | right;
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> se;
        return solve(root,k,se);
    }
};
