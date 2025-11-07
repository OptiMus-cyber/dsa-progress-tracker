class Solution {
public:
    bool solve(vector<int> st, long long mid, int k, int& r) {
        long long sum=0;
        int n=st.size();
        for(int i=0; i<r; i++) sum+=st[i];
        for(int i=0; i<n; ++i) {
            if(i+r<n) sum+=st[i+r];
            if(sum<mid) {
                long long rq=mid-sum;
                if(rq>k) return false;
                st[min(n - 1, i + r)] += rq;
                k-=rq;
                sum+=rq;
            } 
            if(i-r>=0) sum-=st[i-r];
        }
        return true;
    }
    long long maxPower(vector<int>& st, int r, int k) {
        long long mini=*min_element(st.begin(), st.end());
        long long maxi=0;
        for(int i=0; i<st.size(); i++) maxi+=st[i];
        maxi+=k+1;
        while(mini<=maxi) {
            long long mid=(maxi-mini)/2+mini;
            if(solve(st, mid, k, r)) mini=mid+1;
            else maxi=mid-1;
        }
        return maxi;
    }
};