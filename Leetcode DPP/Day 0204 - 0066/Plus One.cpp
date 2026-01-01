class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        reverse(d.begin(), d.end());
        int c=1,n=d.size();
        for(int i=0; i<n; i++) {
            if(d[i]+c>9) {
                d[i]=(d[i]+c)%10;
                c=1;
            } else {
                d[i]=(d[i]+c);
                c=0;
                break;
            }
        }
        if(c) d.push_back(1);
        reverse(d.begin(), d.end());
        return d;
    }
};