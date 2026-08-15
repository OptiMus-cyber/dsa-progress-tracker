class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> arr(26, 0);
        int maxi=0, j=0;
        for(int i=0; i<s.size(); i++) {
            arr[s[i]-'a']++;
            while(arr[s[i]-'a']>2) {
                arr[s[j++]-'a']--;
            }
            maxi=max(maxi, i-j+1);
        }
        return maxi;
    }
};