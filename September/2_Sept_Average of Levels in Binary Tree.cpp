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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        double sum;
        while(!q.empty()){
            int size = q.size();
            sum = 0;
            for(int i = 0;i < size;++i){
                TreeNode* front = q.front();
                q.pop();
                sum += (front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.emplace_back(sum/size);
        }
        return ans;
    }
};
