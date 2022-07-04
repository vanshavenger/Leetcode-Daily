class TrieNode{
    TrieNode* links[27];
    int index;
    public:
    TrieNode* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch,TrieNode* trienode){
        links[ch-'a'] = trienode;
    }
    void setidx(int index){
        this->index = index;
    }
    int getidx(){
        return index;
    }
    
    bool contain(char ch){
        return links[ch-'a'] != NULL;
    }
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    public:
    
    void insert(string word,int index){
        TrieNode* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->contain(word[i])){
                node->put(word[i],new TrieNode());
            }
            node = node->get(word[i]);
            node->setidx(index);

        }
    }
    int startwith(string word){
        TrieNode* node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->contain(word[i])){
                return -1;
            }
            node = node->get(word[i]);
        }
        return node->getidx();
    }
};

class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {
         for(int i = 0;i < words.size();i++){
             for(int j = 0;j < words[i].size();j++){
                trie.insert(words[i].substr(j) + '{' + words[i],i);   
             }
         }
    }
    
    int f(string prefix, string suffix) {
        string se = suffix + '{' + prefix;
        return trie.startwith(se);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
