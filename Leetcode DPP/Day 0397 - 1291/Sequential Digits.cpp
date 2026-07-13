class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int dmin=0, dmax=0, l=low, h=high;
        while(l) {
            dmin++;
            l/=10;
        }
        while(h) {
            dmax++;
            h/=10;
        }
        vector<int> ans;
        for(int i=dmin; i<=dmax; i++) {
            l=1;
            while(1) {
                int x=i, y=l, res=0;
                while(x&&y<=9) {
                    res=res*10+y;
                    y++;
                    x--;
                }
                if(x!=0) break;
                if(res>=low&&res<=high) ans.push_back(res);
                l++;
            }
        }
        return ans;
    }
};