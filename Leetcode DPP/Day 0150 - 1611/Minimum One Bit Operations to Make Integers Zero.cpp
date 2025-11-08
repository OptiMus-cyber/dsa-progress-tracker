class Solution {
public:
    long long final(int x) {
        int res=0;
        while(x>-1) {
            res+=pow(2, x--);
        }
        return res;
    }
    int minimumOneBitOperations(int n) {
        int ans = n;
        ans ^= ans >> 16;
        ans ^= ans >> 8;
        ans ^= ans >> 4;
        ans ^= ans >> 2;
        ans ^= ans >> 1;
        return ans;
        
        // bitset<32> b(n);
        // long long x=-2, st=0;
        // bool pos;
        // for(int i=32; i>=0; i--) {
        //     if(x==-2&&b[i]==1) {
        //         x=i-1;
        //         st=pow(2, i);
        //         pos=false;
        //     } else if(b[i]==1) {
        //         if(pos) {
        //             st+=final(i);
        //             pos=false;
        //         } else {
        //             st-=final(i);
        //             pos=true;
        //         }
        //     }
        // }
        // return st+final(x);
    }
};