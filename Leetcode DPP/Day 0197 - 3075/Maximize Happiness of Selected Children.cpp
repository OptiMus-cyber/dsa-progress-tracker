class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        priority_queue<int> pq;
        for(int i=0; i<hap.size(); i++) {
            pq.push(hap[i]);
        }
        long long c=0, res=0;
        while(!pq.empty()) {
            if(c==k||(pq.top()-c)<=0) break;
            res+=(pq.top()-c);
            pq.pop();
            c++;
        }
        return res;
    }
};