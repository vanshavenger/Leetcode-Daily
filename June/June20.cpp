class Node{
    Node* links[26];
    bool isEnd = false;
    public:
    Node* get(char ch){
        return links[ch - 'a'];
    }
    bool contain(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        isEnd = true;
    }
    bool getEnd(){
        return isEnd;
    }
    void delEnd(){
        isEnd = false;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    public:
    void insert(string str,int & ans){
        Node* node = root;
        for(int i = str.size() - 1;i >= 0;i--){
            if(!node->contain(str[i])){
                node->put(str[i],new Node());
            }
            node = node->get(str[i]);
            if(node->getEnd()){
                ans -= (str.size() - i + 1);
                node->delEnd();
            }
        }
        node->setEnd();
        ans += (str.size() + 1);
        
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size() < b.size();
        });
        int ans = 0;
        for(auto it : words){
            trie.insert(it,ans);
        }
        return ans;
    }
};
