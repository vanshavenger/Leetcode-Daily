class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> se(bank.begin(),bank.end());
        queue<string> q;
        q.push(start);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                string str = q.front();
                q.pop();
                if(str == end) return ans;
                for(int j = 0;j < 8;j++){
                    string org = str;
                    string check = "AGCT";
                    for(auto & it : check){
                        str[j] = it;
                        if(se.find(str) != se.end()) {
                            se.erase(str);
                            q.push(str);
                        }
                    }
                    str = org;
                }
            }
            ans++;
        }
        return -1;
    }
};
