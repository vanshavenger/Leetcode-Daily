class Solution {
public:
    int a,b,c,d,sum,n,i;
    bool solve(vector<int>& match){
        if(i == n){
            if(a == 0 && b == 0 && c == 0 && d == 0) return true;
            else return false;
        }
        if(match[i] <= a){
            a -= match[i];
            i+=1;
            if(solve(match)) return true;
            else i-=1,a += match[i];
        }
        if(match[i] <= b){
            b -= match[i];
            i+=1;
            if(solve(match)) return true;
            else i-=1,b += match[i];
        }
        if(match[i] <= c){
            c -= match[i];
            i+=1;
            if(solve(match)) return true;
            else i-=1,c += match[i];
        }
        if(match[i] <= d){
            d -= match[i];
            i+=1;
            if(solve(match)) return true;
            else i-=1,d += match[i];
        }
        return false;
    }
    bool makesquare(vector<int>& match) {
        n = match.size();
        if(n < 4) return false;
        sum = 0;
        for(auto&it:match){
            sum += it;
        }
        if(sum%4 != 0) return false;
        a = sum/4;
        b = sum/4;
        c = sum/4;
        d = sum/4;
        sort(match.begin(),match.end());
        reverse(match.begin(),match.end());
        i = 0;
        return solve(match);
    }
};
