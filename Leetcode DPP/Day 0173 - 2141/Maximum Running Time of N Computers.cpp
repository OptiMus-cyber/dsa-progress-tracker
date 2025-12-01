class Solution {
public:
    long long calc(long long sum, long long k) {
        if(k==0) return LONG_LONG_MAX;
        return sum/k;
    }
    long long maxRunTime(int n, vector<int>& bat) {
        if(n==bat.size()) return *min_element(bat.begin(), bat.end());
        // Optimising
        long long res=0, sum=0, k=0;
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;
        for(int i=0; i<bat.size(); i++) {
            maxi.push(bat[i]);
            sum+=bat[i];
        }
        if(n==1) return sum;
        while(mini.size()<n) {
            sum-=maxi.top();
            mini.push(maxi.top());
            maxi.pop();
        }
        while(1) {
            long long c=calc(sum, k), top=mini.top()-res, bottom=maxi.top();
            // cout<<res<<" "<<k<<" "<<c<<" "<<top<<endl;
            if(!mini.empty()&&c>top) {
            // cout<<res<<" "<<k<<" "<<c<<endl;
                long long diff=top-bottom;
                res+=diff;
                sum+=bottom-(diff*k);
                mini.pop();
                k++;
            } else return res+c;
        }
        return 0;


        // Brute Force
        // priority_queue<int> maxi;
        // priority_queue<int, vector<int>, greater<int>> mini;
        // long long ans=0;
        // for(int i=0; i<bat.size(); i++) {
        //     maxi.push(bat[i]);
        //     ans+=bat[i];
        // }
        // if(n==1) return ans;
        // while(mini.size()<n) {
        //     mini.push(maxi.top());
        //     maxi.pop();
        // }
        // long long res=0;
        // while(mini.top()) {
        //     int diff=mini.top()-maxi.top()+1;
        //     if(mini.top()-diff<0) diff=mini.top();
        //     res+=diff;
        //     while(!mini.empty()) {
        //         maxi.push(mini.top()-diff);
        //         mini.pop();
        //     }
        //     while(mini.size()<n) {
        //         mini.push(maxi.top());
        //         maxi.pop();
        //     }
        //     // cout<<res<<" "<<mini.top()<<endl;
        // }
        // return res;
    }
};