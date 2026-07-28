class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        string res="";
        string ch="";
        for(auto i: mp) {
            int x=i.second/2;
            while(x) {
                res+=i.first;
                x--;
            }
            if(i.second%2) ch+=i.first;
        }
        string res2=res;
        reverse(res2.begin(), res2.end());
        return res+ch+res2;
    }
};