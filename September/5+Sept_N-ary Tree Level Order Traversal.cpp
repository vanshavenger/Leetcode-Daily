/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        queue<Node*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> curr;
            for(int i = 0;i < size;i++){
                Node* front = q.front();
                q.pop();
                curr.emplace_back(front->val);
                for(auto & it : front->children){
                    q.push(it);
                }
            }
            ans.emplace_back(curr);
        }
        return ans;
    }
};




