/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool solve1(TreeNode* root,TreeNode* op,vector<TreeNode*>& opp){
        if(root == NULL){
            return false;
        }
        if(root->val == op->val){
            opp.push_back(op);
            return true;
        }
        opp.push_back(root);
        bool left = solve1(root->left,op,opp);
        bool right = solve1(root->right,op,opp);
        if(left == true || right == true){
            return true;
        }
        opp.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q){
            return p;
        }
        if(root == NULL){
            return NULL;
        }
        vector<TreeNode*> op;
        vector<TreeNode*> pp;
        bool ee = solve1(root,p,op);
        bool cc = solve1(root,q,pp);
        int size = min(op.size(),pp.size());
        TreeNode* c;
        for(int i = 0;i < size;i++){
            if(op[i]->val != pp[i]->val) break;
            c = op[i];
        }
        return c;
    }
};
