class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int> mps11(26, 0), mps12(26, 0), mps21(26, 0), mps22(26, 0);
        for(int i=0; i<n; i++) {
            if(i%2==0) {
                mps11[s1[i]-'a']++;
                mps21[s2[i]-'a']++;
            } else {
                mps12[s1[i]-'a']++;
                mps22[s2[i]-'a']++;
            }
        }
        for(int i=0; i<26; i++) {
            if(mps21[i]!=mps11[i]) return false;
        }
        for(int i=0; i<26; i++) {
            if(mps22[i]!=mps12[i]) return false;
        }
        return true;
    }
};