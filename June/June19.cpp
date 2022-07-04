class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.size();
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        for(int i = 0;i < n;i++){
            string op = searchWord.substr(0,i+1);
            vector<string> inner;
            for(int j = 0;j < products.size();j++){
                string pp = products[j].substr(0,i+1);
                if(pp == op){
                    inner.push_back(products[j]);
                }
                if(inner.size() == 3){
                    break;
                }
            }
            ans.push_back(inner);
        }
        return ans;
    }
};
