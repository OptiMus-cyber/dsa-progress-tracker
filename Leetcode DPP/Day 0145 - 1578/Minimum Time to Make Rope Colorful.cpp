class Solution {
public:
    int minCost(string clr, vector<int>& time) {
        int res=0, maxi=time[0];
        for(int i=1; i<clr.size(); i++) {
            if(clr[i]==clr[i-1]) {
                res+=min(time[i], maxi);
                maxi=max(time[i], maxi);
            } else {
                maxi=time[i];
            }
        }
        return res;
    }
};