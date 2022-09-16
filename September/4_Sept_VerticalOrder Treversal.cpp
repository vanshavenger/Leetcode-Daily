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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* one = it.first;
            int width = it.second.first;
            int level = it.second.second;
            mp[width][level].insert(one->val);
            if(one->left != NULL){
                q.push({one->left,{width-1,level+1}});
            }
            if(one->right != NULL){
                q.push({one->right,{width + 1,level+1}});
            }
        }
        for(auto wd : mp){
            vector<int> op;
            for(auto it : wd.second){
                for(auto pp : it.second){
                    op.emplace_back(pp);
                }
            }
            ans.push_back(op);
        }
        return ans;
    }
};
