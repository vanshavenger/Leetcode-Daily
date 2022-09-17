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
    void solve(TreeNode* root,vector<int>& a){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            a[root->val]++;
            int odd = 0;
            for(int i = 0;i < a.size();i++){
                if(a[i]%2 == 1)odd++;
            }
            if(odd <= 1) ans++;
            a[root->val]--;
            return;
        }
        a[root->val]++;
        solve(root->left,a);
        solve(root->right,a);
        a[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> a(10,0);
        if(root == NULL) return 0;
        solve(root,a);
        return ans;
    }
};
