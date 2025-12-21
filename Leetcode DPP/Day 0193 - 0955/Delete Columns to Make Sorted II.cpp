class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=strs[0].size(), m=strs.size(), n=strs[0].size();
        vector<bool> del;
        for(int i=0; i<strs[0].size(); i++) {
            int c=0;
            del=vector<bool>(strs[0].size(), false);
            bool f=true;
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][i]<strs[j-1][i]) {
                    f=false;
                    break;
                }
                else if(strs[j][i]==strs[j-1][i]) {
                    int k=i+1;
                    while(k<n) {
                        if(del[k]) {
                            k++;
                            continue;
                        }
                        if(strs[j][k]>strs[j-1][k]) break;
                        else if(strs[j][k]<strs[j-1][k]) {
                            del[k]=true;
                            c++;j=0;
                            break;
                        }
                        k++;
                    }
                }
            }
            if(f) ans=min(ans, c+i);
        }
        return ans;
    }
};