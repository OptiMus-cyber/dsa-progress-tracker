class Solution {
public:
    long long solve(int i, int k, vector<int>& w) {
        cout<<i<<endl;
        if(k==0) return 0;
        if(i==w.size()) return LONG_LONG_MAX;
        long long mini=LONG_LONG_MAX, curr;
        for(int j=0; j<=k; j++) {
            curr=solve(i+1, k-j, w);
            if(curr!=LONG_LONG_MAX) curr=curr+(w[i]*j);
            mini=max(mini, curr);
        }
        return mini;
    }
    long long minNumberOfSeconds(int h, vector<int>& w) {
        // return solve(0, h, w);
        // long long maxi=*max_element(w.begin(), w.end());
        // return (1ll*h*(h+1))/2*maxi;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        for(int i=0; i<w.size(); i++) {
            pq.push({w[i], 1, w[i]});
        }
        long long res=0;
        while(!pq.empty()&&h) {
            auto top=pq.top();
            pq.pop();
            res=max(res, top[2]*(top[1]*(top[1]+1))/2);
            pq.push({top[2]*((top[1]+1)*(top[1]+2))/2, top[1]+1, top[2]});
            h--;
        }
        return res;
    }
};