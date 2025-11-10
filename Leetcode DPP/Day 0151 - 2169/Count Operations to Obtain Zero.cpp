class Solution {
public:
    int countOperations(int num1, int num2) {
        int res=0;
        while(num1&&num2) {
            if(num2<num1) swap(num1, num2);
            num2-=num1;
            res++;
        }
        return res;
    }
};