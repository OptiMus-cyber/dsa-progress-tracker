class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char, int> mps11, mps12, mps21, mps22;
        for(int i=0; i<s1.size(); i++) {
            if(i%2==0) {
                mps11[s1[i]]++;
                mps21[s2[i]]++;
            } else {
                mps12[s1[i]]++;
                mps22[s2[i]]++;
            } 
        }
        for(auto m: mps11) {
            if(mps21[m.first]!=m.second) return false;
        }
        for(auto m: mps12) {
            if(mps22[m.first]!=m.second) return false;
        }
        return true;
    }
};