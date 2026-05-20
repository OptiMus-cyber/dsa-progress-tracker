class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp1, mp2, mp3;
        vector<int> res;
        for(int i=0; i<A.size(); i++) {
            mp1[A[i]]++;
            mp2[B[i]]++;
            if(mp2.count(A[i])) mp3[A[i]]++;
            if(mp1.count(B[i])) mp3[B[i]]++;
            res.push_back(mp3.size());
        }
        return res;
    }
};