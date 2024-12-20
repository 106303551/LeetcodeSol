class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int> fibarray (n,0);
        fibarray[1] = 1;
        for(int i = 2;i<n;i++){
            fibarray[i] = fibarray[i-1]+fibarray[i-2];
        }
        return fibarray[n-1]+fibarray[n-2];
    }
};