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
    TreeNode* solve(vector<int>& pre,int ps,int pe,vector<int>& in,int is,int ie,unordered_map<int,int>& mp){
        if(ps > pe || is > ie){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[ps]);
        int ind = mp[root->val];
        int lele = ind - is;
        root->left = solve(pre,ps+1,ps+lele,in,is,ind-1,mp);
        root->right = solve(pre,ps+1+lele,pe,in,ind+1,ie,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder,0,n-1,inorder,0,n-1,mp);
    }
};
