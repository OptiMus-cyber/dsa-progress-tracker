class Solution {
public:
    static bool comp(int c, int d) {
        int x=0, y=0, a=c, b=d;
        while(a) {
            x+=(a&1);
            a=(a>>1);
        }
        while(b) {
            y+=(b&1);
            b=(b>>1);
        }
        if(x!=y) return x<y;
        return c<d;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;    
    }
};