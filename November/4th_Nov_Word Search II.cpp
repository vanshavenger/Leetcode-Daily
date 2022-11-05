class TrieNode{
    public:
    TrieNode* links[26];
    bool isEnd = false;
    bool contains(char c){
       return links[c - 'a'] != NULL; 
    } 
    void put(char c,TrieNode* node){
        links[c - 'a'] = node;
    }
    TrieNode* get(char c){
        return links[c - 'a'];
    } 
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<string> ans;
    map<TrieNode*,string> mmp;
    int n,m;
    int vis[13][13];
    void insert(string& word){
        TrieNode* node = root;
        for(auto & i : word){
            if(!node->contains(i)){
                node->put(i,new TrieNode());
            }
            node = node->get(i);
        }
        node->isEnd = true;
        mmp[node] = word;
    }
    void dfs(vector<vector<char>>& b,int i,int j,TrieNode* root){
        if(i < 0 || j < 0|| i == n || j == m) return;
        if(vis[i][j]) return;
        if(root == NULL) return;
        TrieNode* child = root->get(b[i][j]);
        if(child == NULL) return;
        if(child->isEnd){
            ans.emplace_back(mmp[child]);
            child->isEnd = false;
        }
        vis[i][j] = 1;
        dfs(b,i+1,j,child);
        dfs(b,i,j+1,child);
        dfs(b,i-1,j,child);
        dfs(b,i,j-1,child);
        vis[i][j] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        for(auto & it : words){
            insert(it);
        }
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                dfs(board,i,j,root);
            }
        }
        return ans;
    }
};
