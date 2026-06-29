class Solution {
public:
    int numOfStrings(vector<string>& pat, string word) {
        int c=0;
        for(int i=0; i<pat.size(); i++) {
            int n=pat[i].size();
            for(int j=0; j<word.size(); j++) {
               // cout<<j<<endl;
                if(pat[i]==word.substr(j, n)) { 
                    c++; 
                    break;
                }
            }
        }
        return c;
    }
};