class Solution {
public:
    void reverse(string& s,int start,int end){
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int b = 0;
        int len = s.length() - 1;
        int j = 0;
        while(b <= s.length()){
            if(s[b] == ' ' || b == s.length()){
                reverse(s,j,b-1);
                j = b+1;
            }
            b++;
        }
        return s;
    }
};
