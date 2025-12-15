class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long c=1, res=0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]-prices[i-1]==-1) {
                c++;
            } else {
                res=res+(c*(c+1))/2;
                c=1;
            }
        }
        res=res+(c*(c+1))/2;
        return res;
    }
};