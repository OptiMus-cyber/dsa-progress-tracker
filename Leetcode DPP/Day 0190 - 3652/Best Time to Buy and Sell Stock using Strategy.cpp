class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long sum=0, res=LONG_LONG_MIN;
        int n=prices.size();
        for(int i=0; i<n; i++) {
            sum+=prices[i]*strategy[i];
        }
        res=max(res, sum);
        for(int i=0; i<n; i++) {
            if(i<k/2) {
                sum+=prices[i]*(-strategy[i]);
            } else if(i<k) {
                sum+=prices[i]*((strategy[i]==-1)?2:(strategy[i]==1)?0:1);
            } else {
                res=max(res, sum);
                sum+=prices[i-k]*(strategy[i-k]);
                sum+=-prices[i-k/2];
                sum+=prices[i]*((strategy[i]==-1)?2:(strategy[i]==1)?0:1);
            }
        }
        res=max(res, sum);
        return res;
    }
};