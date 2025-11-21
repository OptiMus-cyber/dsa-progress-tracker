class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> freq(26, 0), curr(26, 0);
        for(int i=1; i<n; i++) freq[s[i]-'a']++;
        unordered_map<string, int> mp;
        curr[s[0]-'a']++;
        string res(3, 'a');
        for(int i=1; i<n-1; i++) {
            freq[s[i]-'a']--;
            for(int j=0; j<26; j++) {
                if(curr[j]&&freq[j]) {
                    res[0]=res[2]='a'+j;
                    res[1]=s[i];
                    mp[res]++;
                }
            }
            curr[s[i]-'a']++;
        }
        return mp.size();
    }
};