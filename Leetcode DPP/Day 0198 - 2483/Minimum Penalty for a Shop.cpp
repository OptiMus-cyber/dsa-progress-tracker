class Solution {
public:
    int bestClosingTime(string customers) {
        int curr=0, ans, res=0, n=customers.size();
        for(auto i: customers) {
            if(i=='Y') curr++;
        }
        ans=curr;
        for(auto i=0; i<n; i++) {
            if(customers[i]=='N') curr++;
            else curr--;
            if(curr<ans) {
                curr=ans;
                res=i+1;
            }
        }
        return res;
    }
};