class Solution {
public:
    int gc(int a, int b) {
        if (a == 0)
        return b;
        if (b == 0)
            return a;
        if (a == b)
            return a;
        if (a > b)
            return gcd(a - b, b);
        return gcd(a, b - a);
    }
    int gcdOfOddEvenSums(int n) {
        int odd=n*n;
        int even=n*(n+1);
        return gc(odd, even);
    }
};