class Solution {
public:
    bool isPrime(int n) {
        if(n==1) return false;
        if(n==2||n==3||n==5) return true;
        if(n%2==0||n%3==0) return false;
        for(int i=7; i*i<=n; i+=6) {
            if(n%i==0||n % (i + 2) == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left; i<=right; i++) {
            int x=i, c=0;
            while(x) {
                c+=(x%2);
                x/=2;
            }
            cnt+=isPrime(c);
        }
        return cnt;

    }
};