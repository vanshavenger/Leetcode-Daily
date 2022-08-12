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
    TreeNode* solve(int start,int end,vector<int>& nums){
        if(start > end){
            return NULL;
        }
        int middle = start + (end - start)/2;
        TreeNode* create = new TreeNode(nums[middle]);
        if(start == end){
            return create;
        }
        create->left = solve(start,middle-1,nums);
        create->right = solve(middle+1,end,nums);
        return create;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        TreeNode* root = solve(0,nums.size()-1,nums);
        return root;
    }
    
};
